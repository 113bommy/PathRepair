from  math import ceil
def ii():return int(input())
def mi():return map(int,input().split())
def li():return list(mi())
def si():return input()
t=ii()
while(t):
    t-=1
    n,d=mi()
    f=0
    if(d<=n):
        f=1
    else:
        for i in range(1,n+1):
            r=i+ceil(d/(i+1))
           # print(r)
            if(r<=n):
                f=1
                break
    if(f==1):
        print("YES")
    else:
        print("NO")