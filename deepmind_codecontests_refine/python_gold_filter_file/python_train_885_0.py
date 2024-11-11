n,a,b,c=[int(input()) for _ in range(4)]
p=n//a
d=max(-((-n+b-1)//(b-c)),0)
q=d+(n-(b-c)*d)//a
print(max(p,q))

