n,k=input().split()
ls=list(map(int,input().split()))
c=1
pos=1
i=1
while int(k)>c:
    c=ls[i-1]+i
    if c==int(k):
        print("YES")
        break
    if c>int(k):
        print("NO")
        break
    i=c
