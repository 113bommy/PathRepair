
from sys import stdin, stdout

T = int(input())


def summ(n):
	return (n*(n + 1)/2)



for case in range(T):

	n, m = map(int, stdin.readline().split())

	if m >= n/2:
		A = summ(n) - (n - m)
	else:
		# the number of compartments
		c = m + 1
		# splitting the zeros into compartments
		f = (n - m)//c
		f_u = f + 1

		# calculate how many of f_l and f_u there need 
		n_f_u = (n - m) - f*c
		n_f_l = c - n_f_u

		# calculating A
		A = summ(n) - (summ(f_u)*n_f_u + summ(f)*n_f_l)

	print (int(A))




	
