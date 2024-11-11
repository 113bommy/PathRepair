N,M=map(int,input().split())
a=M//N
x=1
for i in range(2,a+1):
    if M%i==0:
        x=i
        if M//i>i and M//i<=a:
            x=M//i
            break
print(x)
