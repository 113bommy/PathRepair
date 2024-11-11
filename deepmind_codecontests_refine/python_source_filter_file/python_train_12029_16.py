a=1234;b= 123456;c=1234567
n=int(input())
for i in range(0,n+1,c):
    for j in range(0,n+1-i,b):
        if (n-i-j)%a:exit(print("YES"))
print("NO")