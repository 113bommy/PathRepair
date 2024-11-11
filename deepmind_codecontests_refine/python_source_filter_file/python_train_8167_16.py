n,k=input().split()
ls=list(map(int,input().split()))
c=1
pos=1
i=0
while int(k)>c:
    c=ls[i]+i+1
    if c==int(k):
        print("YES")
        break
    if c>int(k):
        print("NO")
        break
    i+=1
