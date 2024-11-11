n,m=map(int,input().split())

l1=list(input().split())
l2=list(input().split())

t=int(input())
for _ in range(t):
    n1=int(input())
    s1=""
    s2=""
    d1=0
    d2=0
    d1=n1%n
    d2=n1%m
    if(d1==0):
        s1+=l1[len(l1)-1]
    else:
        s2+=l1[d1-1]
    if(d2==0):
        s1+=l2[len(l2)-1]
    else:
        s2+=l2[d2-1]
    print(s1+s2)
        
        
        