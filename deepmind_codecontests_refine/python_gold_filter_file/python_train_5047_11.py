a,b = map(int,input().split())
r = 0
while b:
    r+=a//b
    a,b=b,a%b
print(r)