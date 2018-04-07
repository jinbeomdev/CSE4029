/*
Student ID : 2013113504
Studnet Name : KIM JIN BEOM

Question 1:
Manhattan Tourist Problem

1)Find the route for the greedy of the Manhattan Tourist Problem.

2)Find the route for the Dynamic Programming of the Manhattan Tourist Problem.

3)Write a Dynamic Prograaming Pseudo-code of the Manhattan Tourist Problem.
MANHATTAN_TOURIST():
	for i = 1 to n
		DP[0][i] = DP[0][i-1]+A[0][i]
		DP[i][0] = DP[i-1][0]+A[i][0]

	for i = 1 to n
		for j = 1 to n
			DP[i][j] = max(DP[i][j-1]+A[i][j],DP[i-1][j]+A[i][j]) 
*/