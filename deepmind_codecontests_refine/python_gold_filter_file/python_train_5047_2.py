a,b=map(int,input().split())
cn=0
while True:
    if a%b != 0:
        d=a%b
        c=a//b
        cn+=c
        a,b=b,d
    else:
        cn+=a/b;break
print(int(cn))