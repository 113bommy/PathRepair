def find(arr):
    return arr[len(arr)-1]-arr[0]

n,k=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
d=[]
for i in range(len(arr)-1):
    c=0
    for j in range(i+1,len(arr)):
        if arr[j]-arr[i]>k:
            d.append(j-i)
            c=1 
            break
    if c==0:
        d.append(len(arr)-i)
d.append(-1)
#print(d)
#print(d)
#print(len(d))
if max(d)==-1:
    print(0)
else:
    print(n-max(d))