n, a, x, b, y= map(int, input().split())


while a!=x and b!=y:
    a = (a+1)%(n+1)
    b = (b-1)%(n)
    if a==0:
        a=1
    if b==0:
        b=5
    if(a==b):
        print("YES")
        break

if(a!=b):
    print("NO")