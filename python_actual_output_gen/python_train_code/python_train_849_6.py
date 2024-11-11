t=int(input())
while(t>0):
    a,b=map(int,input().split())
    x=a
    if (a%b==0):
        print(0)
    else:
        print(a%b)
    t-=1
            
