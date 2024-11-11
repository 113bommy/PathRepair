n=int(input())
ar=[]
for x in range(n):
    l,r=map(int,input().split())
    ar.append([l,r])
e=int(input())
ans=0
mx=0
for x in range(n):
    if(e>=ar[x][1]):
        mx=x
print(n-mx)
