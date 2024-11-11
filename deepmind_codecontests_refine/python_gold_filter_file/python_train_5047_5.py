a,b=map(int,input().split())
s=0
while b!=0:
    s=s+int(a/b)
    a,b=b,a%b
print(s)