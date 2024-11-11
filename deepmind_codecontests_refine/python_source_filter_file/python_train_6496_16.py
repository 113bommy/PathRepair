n,m=map(int,input().split())
A=input().split()
b=1
t=0
for i in A:
    a=int(i)
    if a>=b:
        t+=a-b
    else:
        t+=a-b+4
    b=a
print(t)