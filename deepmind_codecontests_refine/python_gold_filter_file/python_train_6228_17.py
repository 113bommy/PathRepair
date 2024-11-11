def inpl(): return list(map(int, input().split()))
n,m,x,y = inpl()
xs = inpl()
ys = inpl()

if max(xs)>=min(ys) or y<=max(xs) or min(ys)<=x:
    print('War')
else:
    print('No War')