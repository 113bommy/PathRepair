n=int(input())
a=[int(i) for i in input().split()]
k=h=0
for i in range(n):
    if(a[i]==1 or a[i]==n):
        k=i
        break
for i in range(k+1,n):
    if(a[i]==1 or a[i]==n):
        h=i
if(k>(n-h)):
    print(h-1)
else:
    print(n-k-1)