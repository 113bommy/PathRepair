t=int(input())
while t:
    t-=1
    a,b,c=map(int,input().split())
    l=[]
    l.append(a)
    l.append(b)
    l.append(c)
    l.sort()
    k=l[2]-l[1]
    m=l[0]+l[1]
    ans=(k+m)//2
    print(ans)
