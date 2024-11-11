f=lambda(x):x%3==0
a,b=map(int,input().split())
print(['Impossible','Possible'][f(a)or f(b)or f(a+b)])