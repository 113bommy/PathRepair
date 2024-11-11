n=int(input())
for i in range(n):
        a,b,c,m=map(int,input().split())
        m-=(3*max(a,b,c))-a-b-c
        if m>=0 and m%3==0:
                print("YES")
        else:
                print("NO")