#include "shape.h"
#include "calculator.h"
#include <stdexcept>
#include <gtest/gtest.h>

TEST(CalculatorTest, AddTwoPositives){EXPECT_EQ(calculator::add(3, 5), 8);}
TEST(CalculatorTest, AddNegatives){EXPECT_EQ(calculator::add(-3, -5), -8);}
TEST(CalculatorTest, AddMixed){EXPECT_EQ(calculator::add(-3, 5), 2);}
TEST(CalculatorTest, AddZero){EXPECT_EQ(calculator::add(0, 0), 0);}

TEST(CalculatorTest,positiveresult){EXPECT_EQ(calculator::subtract(13, 5), 8);}
TEST(CalculatorTest,negativeresult){EXPECT_EQ(calculator::subtract(3, 5), -2);}
TEST(CalculatorTest,zeroresult){EXPECT_EQ(calculator::subtract(3, 3), 0);}


TEST(CalculatorTest,positivepositive){EXPECT_EQ(calculator::multiply(3,3),9);}
TEST(CalculatorTest,positivenegative){EXPECT_EQ(calculator::multiply(3,-3),-9);}
TEST(CalculatorTest,negativenegative){EXPECT_EQ(calculator::multiply(-3,-3),9);}
  
TEST(CalculatorTest,DivideFoatingPoints){
EXPECT_NEAR(calculator::divide(10.0f, 3.0f), 3.333f, 0.001f);
EXPECT_NEAR(calculator::divide(1.0f, 4.0f), 0.25f, 0.001f);
}
TEST(CalculatorTest,DividebyZero){
EXPECT_THROW(calculator::divide(5.0f, 0.0f), std::invalid_argument);
}

class ShapeTest : public ::testing::Test { 
  protected: 
    /* no shared state needed */ 
};
TEST_F(ShapeTest, CircleArea){EXPECT_NEAR(circle(5).area(), 78.54f, 0.01f);}
TEST_F(ShapeTest, RectangleArea){EXPECT_EQ(rectangle(4,6).area(), 24.0f);}
TEST_F(ShapeTest, TriangleArea){EXPECT_EQ(triangle(6,4).area(), 12.0f);}

int main(int argc,char **argv){
::testing::InitGoogleTest(&argc,argv);
return RUN_ALL_TESTS();
}
