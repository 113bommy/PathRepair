n=int(input())
a=1234567
b=123456
c=1234
for i in range(0,n//a+1):
    d=i*a
    for j in range(0,n//b+1):
        d+=j*b
        if d>n:
            break
        if (n-d)%c==0:
            print("YES")
            exit(0)
print("NO")
