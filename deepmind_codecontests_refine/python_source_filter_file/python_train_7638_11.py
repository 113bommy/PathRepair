'''Author- Akshit Monga'''
n,m,d=map(int,input().split())
arr=[]
for i in range(n):
    temp=[int(x) for x in input().split()]
    for j in temp:
        arr.append(j)
arr=sorted(arr)
ans=0
val=arr[n//2]
for i in arr:
    if abs(i-val)%d!=0:
        ans=-1
        break
    ans+=abs(i-val)//d
print(ans)