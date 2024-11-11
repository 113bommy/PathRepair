b,a=map(int,input().split())
s=0
while a!=0:
    s=s+int(b/a)
    a,b=b,b%a
print(s)