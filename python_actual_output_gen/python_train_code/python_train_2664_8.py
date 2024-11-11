n=int(input())
a=[int(i) for i in input().split()]
m=int(input())
d=sum(a)
flag=0
if(m==0):
    print(-1)
else:
    for i in range(m):
        b,c=[int(i) for i in input().split()]
        if(b==d):
            print(b)
            flag=1
            break
        elif(d<=c):
            print(d)
            flag=1
            break
        else:
            pass
    if(flag==0):
        print(-1)