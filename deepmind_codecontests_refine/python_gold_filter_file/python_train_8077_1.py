from math import sqrt as s
n,k = map(int,input().split())
x,y = int(s(n)),(-1+s(1+4*k))//2
print(['Valera','Vladik'][x<=y])