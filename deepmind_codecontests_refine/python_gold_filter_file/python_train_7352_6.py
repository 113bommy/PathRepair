n=int(input())
a=list(map(int,input().split()))
a,l,r=a[::-1],[1]*n,0
for i in range(n):
    if i+1<=r:l[i]=0
    if r<i+1+a[i]:r=i+a[i]+1
print(sum(l))