#include "pointreader.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest
{
    TEST_CLASS(PointReaderTest)
    {
    public:
        // Test metodoa, sarrera baliodunarekin irakurketa ondo funtzionatzen duela egiaztatzeko 
        TEST_METHOD(TestReadingWorksWithValidInput)
        {
            char const* filename = "points.txt"; // Sarrera fitxategi balioduna
            struct point_t* points; // Puntuen biltegia

            int numberOfPoints = readPoints(filename, &points); // Puntuen irakurketa fitxategitik
            Logger::WriteMessage("In TestReadingWorksWithValidInput");
            Assert::IsTrue(numberOfPoints > 0); // Fitxategia ondo irakurtzen bada, puntuen kopurua 0 baino handiagoa izan behar da
        }
        // Test metodoa, sarrera baliogabearekin irakurketa huts egiten duela egiaztatzeko
        TEST_METHOD(TestReadingNotWorksWithInvalidInput)
        {

            point_t* points;
            int numberOfPoints = readPoints("invalidpoints.txt", &points); // Puntuen irakurketa fitxategi baliogabetik

            Logger::WriteMessage("In TestReadingNotWorksWithInvalidInput");
            Assert::AreEqual(numberOfPoints, -1); // Fitxategia ondo irakurtzen ez bada, funtzioak -1 itzuli behar du

        }

        // Test metodoa, existitzen ez den fitxategiarekin irakurketa huts egiten duela egiaztatzeko
        TEST_METHOD(TestReadingNotWorksWithUnexsistentFile)
        {

            point_t* points;
            int numberOfPoints = readPoints("points.txt", &points);
            Logger::WriteMessage("In TestReadingNotWorksWithUnexsistentFile");// Puntuen irakurketa existitzen ez den fitxategitik
            Assert::AreEqual(numberOfPoints, -2);// Fitxategia existitzen ez bada, funtzioak -2 itzuli behar du
        }
    };
}