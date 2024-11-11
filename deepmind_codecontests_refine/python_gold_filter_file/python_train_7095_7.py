n,a,x,b,y=map(int,input().split())
x=x%n
y=y%n
for i in range(n):
    a=a%n
    b=b%n
    if(a==b):
        print("YES")
        exit()
    if(a==x or b==y):
        print("NO")
        exit()
    a=a+1
    b=b-1
print("NO")