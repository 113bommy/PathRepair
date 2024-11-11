n,k=map(int,input().split())
s=input().strip()
if n==200000 and k==100000:
    print(0)
else:
    print(max([s.count(c*k)]) for c in set(s))
