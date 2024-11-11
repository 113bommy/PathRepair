from sys import stdin
from math import gcd,sqrt
from collections import deque
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\n')
hg=lambda x,y:((y+x-1)//x)*x
n=I()
s=list(S())
dlt=0
for i in range(n-1):
	if (i+1+dlt)%2 and s[i]==s[i+1]:
		s[i]='*'
		dlt+=1
print(dlt+(n-dlt)%2)
print(''.join(s).replace('*','')[(n-dlt)%2:])