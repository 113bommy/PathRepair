a,b,c=map(int,input().split())
if (a*b*c)%2==0:
    print(0)
else:
    l=[a,b,c]
    l.sort()
    print(a*b)