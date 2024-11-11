t=int(input())
for _ in range(t):
    a,b,n,m=map(int,input().split())
    if(a+b<n+m):
        print("No")
    elif(a<b and m>a):
        print("No")
    elif(b<a and m>b):
        print("No")
    else:
        print("Yes")
