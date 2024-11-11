_, *a = map(int, open(0).read().split())
t = map(abs, a)
s = sum(t)
print(s if len([i for i in a if i<0])%2==0 or 0 in a else s-min(t))