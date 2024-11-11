a,b,c,d =map(int,input().split())
l = set(list(map(int,input().split())))
if(abs(a)>c):
    print(0)
    exit(0)
if(a==0):
    if 0 in l:
        print(0)
        exit(0)
    else:
        print("inf")
        exit(0)
if(b==1):
    if a in l:
        print(0)
        exit(0)
    else:
        print("inf")
        exit(0)
if(b==-1):
    if(-a in l) and(a in l):
        print(0)
        exit(0)
    else:
        print("inf")
        exit(0)
if(b==0):
    if 0 in l:
        if a in l:
            print(0)
            exit(0)
        else:
            print("inf")
            exit(0)
    else:
        print("inf")
        exit(0)
ans = 0
while(abs(a)<=c):
    if(a not in l):
       ans+=1
    a = a*b
print(ans)