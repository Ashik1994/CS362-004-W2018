//unit test on getCost() function


#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

int main(){
	
	printf("Performing test on getCost() function \n");
	
	
	
	
	int a = getCost(curse);
	assert (a == curse);
	int b = getCost(1);
	assert (b == 2);
	int c = getCost(2);
	assert (c == 5);
	int d = getCost(3);
	assert (d == 8);
	int e = getCost(4);
	assert (e == 0);
	int f = getCost(5);
	assert (f == 3);
	int g = getCost(6);
	assert (g == 6);
	int h = getCost(7);
	assert (h == 6);
	int i = getCost(8);
	assert (i == 5);
	int j = getCost(9);
	assert (j == 4);
	int k = getCost(10);
	assert (k == 4);
	int l = getCost(11);
	assert (l == 5);
	int m = getCost(12);
	assert (m == 4);
	int n = getCost(13);
	assert (n == 4);
	int o = getCost(14);
	assert (o == 3);
	int p = getCost(15);
	assert (p == 4);
	int q = getCost(16);
	assert (q == 3);
	int r = getCost(17);
	assert (r == 5);
	int s = getCost(18);
	assert (s == 3);
	int t = getCost(19);
	assert (t == 5);   //tribute
	int u = getCost(20);
	assert (u == 3);
	int v = getCost(21);
	assert (v == 4);   //cutpurse
	int w = getCost(22);
	assert (w == 2);
	int x = getCost(23);
	assert (x == 5);
	int y = getCost(24);
	assert (y == 4);
	int z = getCost(25);
	assert (z == 4);
	int aa = getCost(26);
	assert (aa == 4);
	a = getCost(3423);
	assert (a == -1);
	
	printf("Test on getCost() function passed \n");
	
	return 0;
}	
	
	
	