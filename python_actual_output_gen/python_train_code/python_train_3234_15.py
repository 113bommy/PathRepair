t = int(input())
for i in range(t):
    a,b,c,r = map(int,input().split())
    if(a>b):
        t = a
        a = b
        b = t
    ans = b-a+1
    p1 = min(c-r,c+r)
    p2 = max(c-r,c+r)
    if(p1>b or p2<a):
        pass
    elif(p2>=b and p1<=a):
        ans = 0
    elif(p1<a):
        ans = ans - (p2-a+1)
    elif(p2>b):
        ans =  ans - (b-p1+1)
    else:
        ans = ans - (p2-p1+1)
    print(ans)
