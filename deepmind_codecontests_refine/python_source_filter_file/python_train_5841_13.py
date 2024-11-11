# http://codeforces.com/contest/1033/problem/A

n=int(input())
b1,b2=map(int,input().split())             #queen
a1,a2=map(int,input().split())             #king
c1,c2=map(int,input().split())             #target
if(a1<b1 and c1<b1 and a2<b2 and c2<b2):
	print("YES")
if(a1>b1 and c1>b1 and a2<b2 and c2<b2):
	print("YES")
if(a1<b1 and c1<b1 and a2>b2 and c2>b2):
	print("YES")
if(a1>b1 and c1>b1 and a2>b2 and c2>b2):
	print("YES")
else:
	print("NO")