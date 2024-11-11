from math import sqrt as s
n,k = map(int,input().split())
x,y = int(s(k)),(-1+s(1+4*n))//2
print(['Valera','Vladik'][x<=y])