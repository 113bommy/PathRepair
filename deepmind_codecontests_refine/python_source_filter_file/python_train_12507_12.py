n=int(input())
arr=[]
for i in range(n):
	x,y=map(int,input().split())
	arr.append([x,y])
ans=0
k=int(input())
index=-1
k-=1
for i in range(len(arr)):
	if arr[i][0]<=k and k>=arr[i][1]:
		index=i 
		break
print(n-index-1)