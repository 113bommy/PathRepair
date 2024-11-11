from sys import stdin
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
n=I()
tr=list(R())
clr=list(R())
stp=1
for i in range(2,n):
	if clr[i-1]!=clr[tr[i-2]-1]:stp+=1
print(stp)