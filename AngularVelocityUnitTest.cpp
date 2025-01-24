#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "angularvelocitycalculator.h"

// UnitTest izeneko izen-espazioa defintzen da
namespace UnitTest
{
    // AngularVelocityTest izeneko TEST_CLASS definitzen da
    // TEST_CLASS: Test klase bat definitzen du, test metodoak barne hartzen dituena. Test klaseak test kasuak antolatzeko eta exekutatzeko erabiltzen dira.
    TEST_CLASS(AngularVelocityTest)
    {
    public:
        // TestAngularVelocity izeneko TEST_METHOD definitzen da
        // TEST_METHOD: Test metodo bat definitzen du, unit test bat exekutatzeko. Test metodoak funtzio edo metodo jakin baten portaera egiaztatzeko erabiltzen dira.
        // Puntuak definitzen dira
        // Abiadura angeluar maximoa kalkulatzen da
        // Emaitza espero den balioarekin alderazten da
        TEST_METHOD(TestAngularVelocity)
        {
            //Puntuak definitzen dira
            point_t points[] = {
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5},
                {2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0}
            };
            int numberOfPoints = 3;

            // Abiadura angeluar maximoa kalkulatzen da
            float result = computeMaximumAngularVelocity(points, numberOfPoints);
            // Emaitza espero den balioarekin alderazten da
            Assert::AreEqual(1.0f, result);
        }

        // TestNoPoints izeneko TEST_METHOD definitzen da
        TEST_METHOD(TestNoPoints)
        {
            // Puntuak null dira eta puntuen kopurua 0 da
            point_t* points = nullptr;
            int numberOfPoints = 0;

            // Abiadura angeluar maximoa kalkulatzen da
            float result = computeMaximumAngularVelocity(points, numberOfPoints);
            // Emaitza 0.0 dela ziurtatzen da, punturik ez dagoenean
            Assert::AreEqual(0.0f, result); 
        }

        // TestNegativeAngularVelocity izeneko TEST_METHOD definitzen da
        TEST_METHOD(TestNegativeAngularVelocity)
        {
            // Puntuak definitzen dira
            point_t points[] = {
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
                {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0},
                {2.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.2}
            };
            int numberOfPoints = 3;
            // Abiadura angeluar maximoa kalkulatzen da
            float result = computeMaximumAngularVelocity(points, numberOfPoints);
            // Emaitza espero den balioarekin alderazten da, balio absolutu maximoa itzultzen dela suposatuz
            Assert::AreEqual(-0.2f, result); 
        }

        // TestVaryingAngularVelocity izeneko TEST_METHOD definitzen da
        TEST_METHOD(TestVaryingAngularVelocity)
        {
            // Puntuak definitzen dira
            point_t points[] = {
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3},
                {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.7},
                {2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4}
            };
            int numberOfPoints = 3;

            // Abiadura angeluar maximoa kalkulatzen da
            float result = computeMaximumAngularVelocity(points, numberOfPoints);
            // Emaitza espero den balioarekin alderatzen da
            Assert::AreEqual(0.7f, result); //  0.7f balioa espero den emaitza da, eta result kalkulatutako emaitza.
        }
    };
}

