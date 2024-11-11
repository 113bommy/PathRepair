#Codeforces problem 417A: Elimination

def roof(n,p):
	r = p // n
	if p%n > 0:
		r = r + 1
	return r

c,d = (int(element) for element in input().split())

n,m = (int(element) for element in input().split())

k = int(input())

needed_number_of_problems = 0

#people still needed for the 2214 Russian Code Cup"
p = m*n - k

while p > 0:
	x = roof(n,p)
	if d*p < c*x:
		#get people from the additional rounds
		needed_number_of_problems += d
		p = p - 1
	else:
		#get people from main round
		needed_number_of_problems += c
		p = p - n

print(needed_number_of_problems)