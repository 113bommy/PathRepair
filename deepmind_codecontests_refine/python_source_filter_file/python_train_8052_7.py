n=int(input())
x=int(input())
a,b=map(int,input().split())
for i in range(n-1):
    a,b=map(int,input().split())
    s,t,u,v=a,b,7-a,7-b
    if(x==s or x==t or x==u or x==v):
        print("NO")
        break
print("YES")