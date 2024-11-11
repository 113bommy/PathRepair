n=int(input())
d=list(map(int,input().split(" ")))
a,b=map(int,input().split(" "))
s=0
for i in range(b-a):
	s+=d[i]
print(s)