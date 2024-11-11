a,m=map(int,input().split())
flag="NO"
for i in range(10000):
    if a%m==0:
        flag="YES"
        break
    a+=(a%m)
print(flag)