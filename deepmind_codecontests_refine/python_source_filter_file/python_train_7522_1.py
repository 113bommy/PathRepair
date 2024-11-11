t=int(input())
for i in range(t) :
    n=int(input())
    a=list(map(int,input().split()));b=0;c=0
    for j in a :
        b+=i;c=min(c,b)
    print(-c)