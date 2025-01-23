#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "angularvelocitycalculator.h"

namespace UnitTest
{
    TEST_CLASS(AngularVelocityTest)
    {
    public:
        TEST_METHOD(TestAngularVelocity)
        {
            point_t points[] = {
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5},
                {2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0}
            };
            int numberOfPoints = 3;

            float result = computeMaximumAngularVelocity(points, numberOfPoints);
            Assert::AreEqual(1.0f, result);
        }

        TEST_METHOD(TestNoPoints)
        {
            point_t* points = nullptr;
            int numberOfPoints = 0;

            float result = computeMaximumAngularVelocity(points, numberOfPoints);
            Assert::AreEqual(0.0f, result); // Assuming the function returns 0.0 for no points
        }

        TEST_METHOD(TestNegativeAngularVelocity)
        {
            point_t points[] = {
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
                {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0},
                {2.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.2}
            };
            int numberOfPoints = 3;

            float result = computeMaximumAngularVelocity(points, numberOfPoints);
            Assert::AreEqual(-0.2f, result); // Assuming the function returns the maximum absolute value
        }

        TEST_METHOD(TestVaryingAngularVelocity)
        {
            point_t points[] = {
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3},
                {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.7},
                {2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4}
            };
            int numberOfPoints = 3;

            float result = computeMaximumAngularVelocity(points, numberOfPoints);
            Assert::AreEqual(0.7f, result);
        }
    };
}

