def check(arr):
    d=arr[1]-arr[0]
    for i in range(len(arr)-1):
        if arr[i]+d!=arr[i+1]:
            return False
    return True


n=int(input())
arr=list(map(int,input().split()))
ls=sorted(arr)
if n==2:
    print(1)
    exit()


if check(ls[1:]):
    print(arr.index(ls[0]) + 1)
    exit(0)
if  check([ls[0]]+ls[2:]):
    print(arr.index(ls[1]) + 1)
    exit(0)

d=ls[1]-ls[0]
ind=0
for i in range(n-1):
    if ls[i]+d!=ls[i+1]:
        ind=i+1
        break
#print(ls[:ind]+ls[ind+1:])
if check(ls[:ind]+ls[ind+1:]):
    print(arr.index(ls[ind])+1)
    exit(0)
else:
    print(-1)



