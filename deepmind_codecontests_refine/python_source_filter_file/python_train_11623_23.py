v1, v2, v3, vm = map(int, input().split())
b = True
c1 = 2*v1
c3 = max(v3, vm)
c2 = max(c1-1, 2*v2)
b = (c1 >= max(v1, 2*vm+1)) and (c3 <= min(2*vm, 2*v3)) and (c2 >= max(2*vm+1, v2, c3+1))
if b:
    print(c1)
    print(c2)
    print(c3)
else:
    print(-1)
