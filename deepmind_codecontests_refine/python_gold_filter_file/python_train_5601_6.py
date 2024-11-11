n=int(input())
a=list(map(int,input().split()))
x=0
for t in a:
	x+=1/t
print(1/x)