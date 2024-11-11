n,m=map(int,input().split())
c=list(map(int,input().split()))
a=list(map(int,input().split()))
j=0
for i in c:
    if j<m and i<=a[j]:
        j+=1 