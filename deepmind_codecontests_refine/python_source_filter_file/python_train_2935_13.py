n=int(input())
t=0
a=[[0 for i in range(n)]for j in range(n)]
for i in range(n):
    c=i
    r=0
    for j in range(i+1):
        if t%2==0:
            a[r][c]="W"
        else:
            a[r][c]="B"
        c-=1
        r+=1
    t+=1

for i in range(1,n):
    c=n-1
    r=i
    for j in range(n-i):
        if t%2==0:
            a[r][c]="W"
        else:
            a[r][c]="B"
        c-=1
        r+=1
    t+=1
for i in range(n):
    print(*a[i],sep=" ")