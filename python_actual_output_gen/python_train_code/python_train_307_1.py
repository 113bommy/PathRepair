n,a,b,c=[int(input()) for _ in range(4)]
p=n//a
d=-((-n+b-1)//(b-c))
q=d+(n-(b-c)*d)//a
print(max(p,q))

