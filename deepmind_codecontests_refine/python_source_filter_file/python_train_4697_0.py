a = [int(i) for i in input().strip().split()]
a.sort()
if sum(a[:2])<a[2]:
    print(0)
else:
    print(a[2]-sum(a[:2])+1)