#include "pch.h"
#include "../List/tpolinom.h"
#include "../List/theadlist.h"
#include "../List/tlist.h"

TEST(TPolinomTest, can_create_monom) {
	int arr[1][2];
	arr[0][0] = 1;
	arr[0][1] = 111;
	ASSERT_NO_THROW(TMonom monom(arr));
	TMonom monom(arr);
	EXPECT_EQ(monom.coeff, 1);
	EXPECT_EQ(monom.px, 1);
	EXPECT_EQ(monom.py, 1);
	EXPECT_EQ(monom.pz, 1);
}
TEST(TPolinomTest, can_create_polinom) {
	int sizem = 2; 
	int column = 2;
	int** arr;
	arr = new int*[sizem];
	for (int i = 0; i < sizem; i++)
		arr[i] = new int[column];
	arr[0][0] = 1;
	arr[0][1] = 111;
	arr[1][0] = 2;
	arr[1][1] = 222;
	ASSERT_NO_THROW(TPolinom pol(arr, sizem));
	TPolinom pol(arr, sizem);
	pol.Reset();
	EXPECT_EQ(pol.GetMonom().coeff, 2);
	EXPECT_EQ(pol.GetMonom().px, 2);
	EXPECT_EQ(pol.GetMonom().py, 2);
	EXPECT_EQ(pol.GetMonom().pz, 2);
	pol.GoNext();
	EXPECT_EQ(pol.GetMonom().coeff, 1);
	EXPECT_EQ(pol.GetMonom().px, 1);
	EXPECT_EQ(pol.GetMonom().py, 1);
	EXPECT_EQ(pol.GetMonom().pz, 1);
}
TEST(TPolinomTest, can_assign_one_polimonial_to_another) {
	int sizem = 2;
	int column = 2;
	int** arr;
	arr = new int*[sizem];
	for (int i = 0; i < sizem; i++)
		arr[i] = new int[column];
	arr[0][0] = 1;
	arr[0][1] = 111;
	arr[1][0] = 2;
	arr[1][1] = 222;
	TPolinom pol(arr, sizem);
	int sizem1 = 2;
	int column1 = 2;
	int** arr1;
	arr1 = new int*[sizem1];
	for (int i = 0; i < sizem1; i++)
		arr1[i] = new int[column1];
	arr1[0][0] = 3;
	arr1[0][1] = 333;
	arr1[1][0] = 4;
	arr1[1][1] = 444;
	TPolinom pol1(arr1, sizem1);
	ASSERT_NO_THROW(pol = pol1);
	pol.Reset();
	EXPECT_EQ(pol.GetMonom().coeff, 4);
	EXPECT_EQ(pol.GetMonom().px, 4);
	EXPECT_EQ(pol.GetMonom().py, 4);
	EXPECT_EQ(pol.GetMonom().pz, 4);
	pol.GoNext();
	EXPECT_EQ(pol.GetMonom().coeff, 3);
	EXPECT_EQ(pol.GetMonom().px, 3);
	EXPECT_EQ(pol.GetMonom().py, 3);
	EXPECT_EQ(pol.GetMonom().pz, 3);
}
TEST(TPolinomTest, can_add_monom_to_polinom) {
	int sizem = 2;
	int column = 2;
	int** arr;
	arr = new int*[sizem];
	for (int i = 0; i < sizem; i++)
		arr[i] = new int[column];
	arr[0][0] = 1;
	arr[0][1] = 111;
	arr[1][0] = 2;
	arr[1][1] = 222;
	TPolinom pol(arr, sizem);
	int arrm[1][2];
	arrm[0][0] = 3;
	arrm[0][1] = 333;
	TMonom monom(arrm);
	ASSERT_NO_THROW(pol.InsMonom(monom));
	//pol.InsMonom(monom);
	pol.Reset();
	EXPECT_EQ(pol.GetMonom().coeff, 3);
	EXPECT_EQ(pol.GetMonom().px, 3);
	EXPECT_EQ(pol.GetMonom().py, 3);
	EXPECT_EQ(pol.GetMonom().pz, 3);
	pol.GoNext();
	EXPECT_EQ(pol.GetMonom().coeff, 2);
	EXPECT_EQ(pol.GetMonom().px, 2);
	EXPECT_EQ(pol.GetMonom().py, 2);
	EXPECT_EQ(pol.GetMonom().pz, 2);
	pol.GoNext();
	EXPECT_EQ(pol.GetMonom().coeff, 1);
	EXPECT_EQ(pol.GetMonom().px, 1);
	EXPECT_EQ(pol.GetMonom().py, 1);
	EXPECT_EQ(pol.GetMonom().pz, 1);
}
TEST(TPolinomTest, can_multiply_the_polinomial_by_a_constant) {
	int sizem = 2;
	int column = 2;
	int** arr;
	arr = new int*[sizem];
	for (int i = 0; i < sizem; i++)
		arr[i] = new int[column];
	arr[0][0] = 1;
	arr[0][1] = 111;
	arr[1][0] = 2;
	arr[1][1] = 222;
	TPolinom pol(arr, sizem);
	int a = 3;
	ASSERT_NO_THROW(pol *= a);
	pol.Reset();
	EXPECT_EQ(pol.GetMonom().coeff, 6);
	EXPECT_EQ(pol.GetMonom().px, 2);
	EXPECT_EQ(pol.GetMonom().py, 2);
	EXPECT_EQ(pol.GetMonom().pz, 2);
	pol.GoNext();
	EXPECT_EQ(pol.GetMonom().coeff, 3);
	EXPECT_EQ(pol.GetMonom().px, 1);
	EXPECT_EQ(pol.GetMonom().py, 1);
	EXPECT_EQ(pol.GetMonom().pz, 1);
}
TEST(TPolinomTest, can_multiply_the_polinomial_by_a_monomial) {
	int sizem = 2;
	int column = 2;
	int** arr;
	arr = new int*[sizem];
	for (int i = 0; i < sizem; i++)
		arr[i] = new int[column];
	arr[0][0] = 1;
	arr[0][1] = 111;
	arr[1][0] = 2;
	arr[1][1] = 222;
	TPolinom pol(arr, sizem);
	int arrm[1][2];
	arrm[0][0] = 3;
	arrm[0][1] = 333;
	TMonom monom(arrm);
	ASSERT_NO_THROW(pol *= monom);
	pol.Reset();
	EXPECT_EQ(pol.GetMonom().coeff, 6);
	EXPECT_EQ(pol.GetMonom().px, 5);
	EXPECT_EQ(pol.GetMonom().py, 5);
	EXPECT_EQ(pol.GetMonom().pz, 5);
	pol.GoNext();
	EXPECT_EQ(pol.GetMonom().coeff, 3);
	EXPECT_EQ(pol.GetMonom().px, 4);
	EXPECT_EQ(pol.GetMonom().py, 4);
	EXPECT_EQ(pol.GetMonom().pz, 4);
}
TEST(TPolinomTest, can_add_two_polinomials) {
	int sizem = 2;
	int column = 2;
	int** arr;
	arr = new int*[sizem];
	for (int i = 0; i < sizem; i++)
		arr[i] = new int[column];
	arr[0][0] = 1;
	arr[0][1] = 111;
	arr[1][0] = 2;
	arr[1][1] = 222;
	TPolinom pol(arr, sizem);
	int sizem1 = 2;
	int column1 = 2;
	int** arr1;
	arr1 = new int*[sizem1];
	for (int i = 0; i < sizem1; i++)
		arr1[i] = new int[column1];
	arr1[0][0] = -2;
	arr1[0][1] = 222;
	arr1[1][0] = 4;
	arr1[1][1] = 444;
	TPolinom pol1(arr1, sizem1);
	TPolinom res;
	ASSERT_NO_THROW(res = pol + pol1);
	res.Reset();
	EXPECT_EQ(res.GetMonom().coeff, 4);
	EXPECT_EQ(res.GetMonom().px, 4);
	EXPECT_EQ(res.GetMonom().py, 4);
	EXPECT_EQ(res.GetMonom().pz, 4);
	res.GoNext();
	EXPECT_EQ(res.GetMonom().coeff, 1);
	EXPECT_EQ(res.GetMonom().px, 1);
	EXPECT_EQ(res.GetMonom().py, 1);
	EXPECT_EQ(res.GetMonom().pz, 1);
}
TEST(TPolinomTest, can_output_polinomials) {
	int sizem = 2;
	int column = 2;
	int** arr;
	arr = new int*[sizem];
	for (int i = 0; i < sizem; i++)
		arr[i] = new int[column];
	arr[0][0] = 1;
	arr[0][1] = 111;
	arr[1][0] = 2;
	arr[1][1] = 222;
	TPolinom pol(arr, sizem);
	ASSERT_NO_THROW(std::cout << pol);
}