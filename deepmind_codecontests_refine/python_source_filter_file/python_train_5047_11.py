a,b=map(int,input().split())
k=1
while b:
    k+=a//b
    a,b=b,a%b
print(k)