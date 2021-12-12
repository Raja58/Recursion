// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        21 Nov 2021
//  @Detail  :        Josephus
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
	if(n == 1)
		return 0;
	return (jos(n - 1, k) + k) % n;
}
