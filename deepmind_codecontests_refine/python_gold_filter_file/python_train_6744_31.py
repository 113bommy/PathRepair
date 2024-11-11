n=int(input())
a=list(map(int,input().split()))
mem=[0]*n

for i in a:
	mem[i-1]+=1

for i in mem:
	print(i)