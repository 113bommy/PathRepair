n=int(input())
l=list(map(int,input().split()))
m=-369
for i in range(n):
    c=0
    for j in range(i,n):
        c=c^l[j]
    m=max(m,c)
print(m)
