n=int(input())
a=list(map(int,input().split()))
mem=[0]*10

for i in a:
	mem[i-1]+=1

for i in mem:
	print(i)