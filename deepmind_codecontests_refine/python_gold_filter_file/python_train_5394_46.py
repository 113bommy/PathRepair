_,*l=map(int,open(0).read().split())
l.sort()
print("YNeos"[sum(l[:-1])<=l[-1]::2])