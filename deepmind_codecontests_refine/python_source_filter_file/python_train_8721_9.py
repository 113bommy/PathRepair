n,m=map(int,input().split());a=sorted(map(int,input().split()),reverse=True)[:m]
print('NYoe s'[all([1 if i>=sum(a)/(4*m) else 0 for i in a])::2])