a,b,c,n = map(int,input().split())

if (n-(a+b-c))>0 and a>c and b>c:
    print ((n-(a+b-c)))
else:
    print(-1)
