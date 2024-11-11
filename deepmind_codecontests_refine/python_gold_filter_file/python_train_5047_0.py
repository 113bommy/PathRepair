a,b=map(int,input().split())
k=0
while b:
    k+=a//b
    a,b=b,a%b
print(k)