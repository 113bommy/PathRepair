f=lambda : list(map(int,input().split()))
n,m=f()
lr=lambda x: x[1]-x[0]+1
sq=min(lr(f()) for _ in range(m))
print(sq)
x=' '.join([str(i%n) for i in range(n)])
print(x)
