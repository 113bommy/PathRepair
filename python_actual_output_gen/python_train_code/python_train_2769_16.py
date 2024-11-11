n=int(input())
l=list(map(int,input().split()))
l.sort()
if len(l)<=2:
    print(sum(l))
else:
    s=2*sum(l)
    temp=sum(l)
    for i in range(0,n-2):
        temp=temp-l[i]
        s=s+temp
    print(s)