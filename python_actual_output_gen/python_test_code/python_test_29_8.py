n=int(input())
l=list(map(int,input().split()))
m=1
for i in range(n):
    if i==0:
        j=1
        c=1
        while j<n and l[j]<=l[j-1]:
            c=c+1
            j=j+1
        m=max(m,c)
    elif i==n-1:
        j=n-2
        c=1
        while j>0 and l[j]<=l[j+1]:
            c=c+1
            j=j-1
        m=max(m,c)
    else:
        j=i+1
        c=1
        while j<n and l[j]<=l[j-1]:
            c=c+1
            j=j+1
        j=i-1
        while j>0 and l[j]<=l[j+1]:
            c=c+1
            j=j-1
        m=max(m,c)
print(m)