n=int(input()) 
l=[]
for i in range (n):
	a=list(map(int,input().split()))
	l.append(a)
a=int(input())
for i in range(n):
	if a<l[i][1]:
		print(n-i)
		break