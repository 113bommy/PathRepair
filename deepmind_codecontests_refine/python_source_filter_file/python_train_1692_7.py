def swap(x,y):
  return y,x

t=int(input())
while(t):
    t-=1
    f=1
    c=0
    a,b=[int(x) for x in input().split(" ")]
    if(a<b):
        a,b=swap(a,b)
    while a!=b:
        if((a%2==0 and a//2==b) or (a%4==0 and a//4==b) or (a%8==0 and a//8==b)):
            c+=1
            break
        if a%8==0:
            c+=1
            a/=8
        elif a%4==0:
            c+=1
            a/=4
        elif a%2==0:
            c+=1
            a/=2
        else:
            f=0
            break
    if f:
        print(c)
    else:
        print("-1")
