a=sorted(map(int,input().split()))
s=sum(a)
print("YNEOS"[s%2 or s in [sum(a[1:]),sum(a[1:3])]::2])