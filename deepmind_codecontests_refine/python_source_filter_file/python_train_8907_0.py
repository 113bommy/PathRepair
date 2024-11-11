#input template
from sys import stdin, stdout
cin = stdin.readline
cout = stdout.write
mp = lambda: list(map(int, cin().split()))

def chars(): #function for taking string input as character array since string in python is immutable
    s = cin()
    return(list(s[:len(s) - 1]))

#print list	
def pl(a):	
	for val in a:
		cout(val + '\n')
		
#main

def binSearch(lo, hi):
	high = len(l) - 1
	low = 0
	ans = -1
	while low <= high:
		mid = (low+high)//2
		#print(mid, l[mid])
		if hi>=l[mid] and l[mid]>= lo:
			ans = l[mid]
			#print(ans, 120)
			low = mid+1
		elif l[mid] < lo:
			low = mid+1
		elif l[mid] > hi:
			high = mid-1
	return ans


a, b = sorted(mp())
n, =  mp()

s = set()
for i in range(1, int(a**.5)+1):
	if not a%i and not b%i:
		s.add(i)
		if not a%(a//i) and not b%(b//i):
			s.add(a//i)

l = sorted(s)
#print(l)			
for _ in range(n):
	lo, hi = mp()
	
	ans = binSearch(lo, hi)
	cout(str(ans) + '\n')