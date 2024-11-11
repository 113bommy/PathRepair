n=int(input())
num=[]
for i in range(n):
	i,j=map(int,input().split())
	num.append(j)
k=int(input())-1
ans=0
while num[ans]<k:
	ans+=1
print(n-ans)