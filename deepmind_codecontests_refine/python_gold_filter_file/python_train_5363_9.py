n,p,q = map(int,input().split())
s = input()
a=0
if len(s)%p==0:
    a = len(s)//p
    b = 0
else:
    for i in range(0,200):
        rem = len(s) - a
        if rem%q == 0:
            a = a//p
            b = rem//q
            break
        if rem < 0 :
            a = -1
            b = -1
            break
        a+=p
if a<0 or b<0:
    print(-1)
else:
    print(a+b)
    for i in range(0,a):
        ss = s[0:p]
        print(ss)
        s = s[p:]
    for i in range(0,b):
        ss = s[0:q]
        print(ss)
        s = s[q:]    
