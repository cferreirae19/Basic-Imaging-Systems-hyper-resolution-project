#include "fpimage.h"
#include "ui_fpimage.h"

#include <QFileDialog>
#include <QPainter>

#include <math.h>



//-------------------------------------------------
//-- Constructor: Conexiones e inicializaciones ---
//-------------------------------------------------
FPImage::FPImage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FPImage)
{

    ui->setupUi(this);

    // CONEXIONES de nuestros objetos (botones, etc...) a nuestros slots
    connect(ui->BSelectFile,SIGNAL(clicked()),this,SLOT(Load()));
    connect(ui->BRestore,SIGNAL(clicked()),this,SLOT(DoIt()));

    // Synchronize the scroll bars of both Ecrans
    connect((const QObject*)ui->scrollArea->verticalScrollBar(), SIGNAL(valueChanged(int)),(const QObject*)ui->scrollArea_2->verticalScrollBar(), SLOT(setValue(int)));
    connect((const QObject*)ui->scrollArea_2->verticalScrollBar(), SIGNAL(valueChanged(int)),(const QObject*)ui->scrollArea->verticalScrollBar(), SLOT(setValue(int)));
    connect((const QObject*)ui->scrollArea->horizontalScrollBar(), SIGNAL(valueChanged(int)),(const QObject*)ui->scrollArea_2->horizontalScrollBar(), SLOT(setValue(int)));
    connect((const QObject*)ui->scrollArea_2->horizontalScrollBar(), SIGNAL(valueChanged(int)),(const QObject*)ui->scrollArea->horizontalScrollBar(), SLOT(setValue(int)));


    // INICIALIZACIONES
    Wlow=Hlow=0;      // Empezamos sin imagen cargada
    Path="..";  // Carpeta inicial

}

//-------------------------------------------------
//------ Destructor: Limpieza antes de salir ------
//-------------------------------------------------
FPImage::~FPImage()
{

    delete ui;

}

//-------------------------------------------------
//--------- Load and show a low-res image ---------
//-------------------------------------------------
void FPImage::Load(void)
{

    QString file=QFileDialog::getOpenFileName(this,tr("Open image"),Path,tr("BMP Image Files (*.bmp)"));
    if(file.isEmpty()) return;

	// Extract the base name common to all low-resolution images
    QFileInfo finfo(file);
    Path=finfo.path();
    BaseName=finfo.baseName();
    BaseName=BaseName.left(BaseName.indexOf('_'));

	// Show the base name in the screen and in the window title
    ui->EFile->setText(BaseName);
    setWindowTitle("Super resolutive v0.1b - "+BaseName);

	// Load the first low-resolution image
    QImage LowRes(Path+"/"+BaseName+"_"+QString::number(0)+"_"+QString::number(0)+".bmp");
	// Make sure the pixel matrix is in the right format (R|G|B|R|G|B|R|G|B|... 1 byte per channel)
    LowRes=LowRes.convertToFormat(QImage::Format_RGB888);

    // Get the relevant image parameters
    Wlow=LowRes.width();
    Hlow=LowRes.height();
    Slow=LowRes.bytesPerLine();
    uchar *pixlow=LowRes.bits();

    // Show the LowRes image in the screen with x25 magnified pixels
    QImage AuxIma=LowRes.scaled(25*Wlow,25*Hlow);
    ui->Ecran->setPixmap(QPixmap::fromImage(AuxIma));

	// Show the suspect in the screen
    AuxIma.load(Path+"/Suspect.jpg");
    ui->EcranSuspect->setPixmap(QPixmap::fromImage(AuxIma));

}

//----------------------------------------------------------------------------
//-------------- Build high-res image (square transfer function) -------------
//----------------------------------------------------------------------------
void FPImage::DoIt(void)
{

    // Make sure a base name was selected (with Load button)
    if(BaseName.isEmpty()) return;
    ui->ERes->appendPlainText("Building "+BaseName);

    // Sacamos algo de texto informativo
    ui->ERes->appendPlainText("Doing it");

    //This may come in handy: Prepare an empty HiRes pixel matrix
    const int W = 5*Wlow+4;
    const int H = 5*Hlow+4;
    const int S = 3*W; // No padding in our custom image
    uchar *HiRes=new uchar[S*H]; // A uchar matrix for the *final* HiRes image
    memset(HiRes,0,S*H); // Clean slate
    float *floatHiRes=new float[S*H]; // A uchar matrix for the *final* HiRes image
    memset(floatHiRes,0,S*H); // Clean slate

    // Reads all the 25 images
    for (int a=0; a<5; a++) for (int b=0; b<5; b++) {
        // Load the first low-resolution image
        QImage LowRes(Path+"/"+BaseName+"_"+QString::number(a)+"_"+QString::number(b)+".bmp");
        // Make sure the pixel matrix is in the right format (R|G|B|R|G|B|R|G|B|... 1 byte per channel)
        LowRes=LowRes.convertToFormat(QImage::Format_RGB888);
        // QImage -> Pointer
        uchar *pixlow=LowRes.bits();

        // Do the thing, i.e. build a HiRes from the LowRes images
        for(int y=0;y<(H-4);y++) for(int x=0;x<(W-4);x++) {
            floatHiRes[y*S+b*S+3*x+3*a] += pixlow[y/5*Slow+x/5*3];
            floatHiRes[y*S+b*S+3*x+3*a+1] += pixlow[y/5*Slow+x/5*3+1];
            floatHiRes[y*S+b*S+3*x+3*a+2] += pixlow[y/5*Slow+x/5*3+2];
        }
    }

    // Cast from float to uchar
    // Do the thing, i.e. build a HiRes from the LowRes images
    for(int y=0;y<H;y++) for(int x=0;x<W;x++) {
        HiRes[y*S+3*x] = (unsigned char) (floatHiRes[y*S+3*x]/25);
        HiRes[y*S+3*x+1] = (unsigned char) (floatHiRes[y*S+3*x+1]/25);
        HiRes[y*S+3*x+2] = (unsigned char) (floatHiRes[y*S+3*x+2]/25);
    }
	
	// ShowIt!
    ui->EcranBis->setPixmap(QPixmap::fromImage(QImage(HiRes,W,H,S,QImage::Format_RGB888).scaled(5*W,5*H)));

    // Clean up after yourself
    delete [] HiRes;
    delete [] floatHiRes;

    statusBar()->showMessage("Done.");
       
}


//---------------------------------------------------------------------------
//-------------- Build high-res image (delta transfer function) -------------
//---------------------------------------------------------------------------
void FPImage::on_BRestoreDelta_clicked()
{

    // Make sure a base name was selected (with Load button)
    if(BaseName.isEmpty()) return;
    ui->ERes->appendPlainText("Building "+BaseName);

    // Sacamos algo de texto informativo
    ui->ERes->appendPlainText("Doing it");

    //This may come in handy: Prepare an empty HiRes pixel matrix
    const int W = 5*Wlow+4;
    const int H = 5*Hlow+4;
    const int S = 3*W; // No padding in our custom image
    uchar *HiRes=new uchar[S*H]; // A uchar matrix for the *final* HiRes image
    memset(HiRes,0,S*H); // Clean slate
    float *floatHiRes=new float[S*H]; // A uchar matrix for the *final* HiRes image
    memset(floatHiRes,0,S*H); // Clean slate

    // Reads all the 25 images
    for (int a=0; a<5; a++) for (int b=0; b<5; b++) {
        // Load the first low-resolution image
        QImage LowRes(Path+"/"+BaseName+"_"+QString::number(a)+"_"+QString::number(b)+".bmp");
        // Make sure the pixel matrix is in the right format (R|G|B|R|G|B|R|G|B|... 1 byte per channel)
        LowRes=LowRes.convertToFormat(QImage::Format_RGB888);
        // QImage -> Pointer
        uchar *pixlow=LowRes.bits();

        // Do the thing, i.e. build a HiRes from the LowRes images
        for(int y=0;y<Hlow;y++) for(int x=0;x<Wlow;x++) {
            floatHiRes[5*y*S+b*S+5*3*x+3*a+6] += pixlow[y*Slow+3*x];
            floatHiRes[5*y*S+b*S+5*3*x+3*a+6+1] += pixlow[y*Slow+3*x+1];
            floatHiRes[5*y*S+b*S+5*3*x+3*a+6+2] += pixlow[y*Slow+3*x+2];
        }
    }

    // Cast from float to uchar
    // Do the thing, i.e. build a HiRes from the LowRes images
    for(int y=0;y<H;y++) for(int x=0;x<W;x++) {
        HiRes[y*S+3*x] = (unsigned char) floatHiRes[y*S+3*x];
        HiRes[y*S+3*x+1] = (unsigned char) floatHiRes[y*S+3*x+1];
        HiRes[y*S+3*x+2] = (unsigned char) floatHiRes[y*S+3*x+2];
    }

    // ShowIt!
    ui->EcranBis->setPixmap(QPixmap::fromImage(QImage(HiRes,W,H,S,QImage::Format_RGB888).scaled(5*W,5*H)));

    // Clean up after yourself
    delete [] HiRes;
    delete [] floatHiRes;

    statusBar()->showMessage("Done.");

}

