
n=int(input())
l=[int(i) for i in input().split()]
a=[0]*n
k=10**6
a[0]=min(a[0]-1,k-a[0])
for i in range(1,n):
    a[i]=min(l[i]-1,k-l[i])
print (max(a))