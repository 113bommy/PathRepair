def reverseAtIndex(str,i):
	s = "".join(reversed(str[:i]))
	s = list(s)
	s.extend(str[i:])
	return s

def findDiv(n):
	sol = []
	for i in range(1,n+1):
		if(n%i == 0):
			sol.append(i)
	return sol
	
n = int(input())
str = input()
str = list(str)
for i in findDiv(len(str)):
	str = reverseAtIndex(str,i)
sol = "".join(str)
print(sol)
