n=int(input())
m=list(map(int,input().split()))
last=0
s=sum(m)
if s%2==0:
    print(s)
else:
    for i in range(n):
        if m[i]%2!=0:
            s-m[i]>last
            last=s-m[i]
    print(last)
