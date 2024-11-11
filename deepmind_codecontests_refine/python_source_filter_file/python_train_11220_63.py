from sys import exit

n=int(input())
A=list(map(int,input().split()))
A.sort()

tmp=1
for a in A:
	tmp*=a
	if tmp>10**8:
		print("-1")
		exit()

print(tmp)