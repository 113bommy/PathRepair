a,b=[int(x) for x in input().split()]
arr=[]
#ans=[]
for i in range(b,0,-1):
    curr=i
    c=0
    while curr&1==0:
        c+=1
        curr=curr>>1
    if 2**c<=a:
        a-=2**c
        arr.append(2**c)
if arr:
    print(len(arr))
    print(*arr)
else:
    print(-1)