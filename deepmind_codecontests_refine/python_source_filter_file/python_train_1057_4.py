a,b,c=map(int,input().split())
d=a//c
d+=b//c
g=(a+b)//c
print(g,(g-d)*c-max(a%c,b%c))