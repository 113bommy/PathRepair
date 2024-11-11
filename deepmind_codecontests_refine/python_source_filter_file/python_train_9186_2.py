n=int(input())
l=list(map(int,input().split()))
m=0
if n<3:
    for i in range(n):
        m=m|l[i]
for i in range(n):
    for j in range(i+1,n):
            u=l[i]|l[j]
            for k in range(i+1,n):
                m=max(m,l[i]|u)
print(m)