x=int(input())
ar=list(map(int,input().split()))[:x]
ar.sort()
k=0
for i in range(0,x-2):
    if ((ar[i]+ar[i+1])>ar[i+2]):
        k=k+1
if k>0:
    print("YES")
else:
    print("N0")