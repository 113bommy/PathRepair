n,k,x=map(int,input().split(' '))
m=list(map(int,input().split(' ')))
e=0
for i in range(n):
    e+=m[i]
for i in range(k):
    j=n-1-i
    if m[j]>x:
        e=e-m[j]+x
print(e)