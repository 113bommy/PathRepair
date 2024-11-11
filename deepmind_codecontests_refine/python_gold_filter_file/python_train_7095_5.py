n,a,x,b,y = map(int,input().split())
x = x+n if a > x else x
b = b+n if b < y else b
for i in range(0,min(x-a,b-y)):
    a += 1
    b -= 1
    if a % n == b % n:
        print("YES")
        break
else:
    print("NO")
