n,m=[int(x) for x in input().split()]
l=list(map(int,input().split()))
k=l[0]
for i in range(m-1):
    if l[i]<=l[i+1]:
        k+=l[i+1]-l[i]
    else:
        k+=n-l[i]+l[i+1]
print(k)