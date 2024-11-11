t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    if(abs(a-b)+abs(b-c)+abs(a-c)==1 or abs(a-b)+abs(b-c)+abs(a-c)==2 or abs(a-b)+abs(b-c)+abs(a-c)==3 or abs(a-b)+abs(b-c)+abs(a-c)==0):
        print(0)
    else:
        mini=abs(a-b)+abs(b-c)+abs(a-c)
        x=max(a,b,c)
        y=min(a,b,c)
        z=a+b+c-x-y
        x-=1
        y+=1
        h=abs(x-y)+abs(y-z)+abs(x-z)
        z-=1
        k=abs(x-y)+abs(y-z)+abs(x-z)
        z+=2
        i=abs(x-y)+abs(y-z)+abs(x-z)
        print(min(h,k,i))
