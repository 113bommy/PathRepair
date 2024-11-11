def R(): return map(int, input().split())


ans = []
n, q = R()
d = (n*n+1)//2
for _ in range(q):
    x, y = R()
    i = int(((x-1)*n+y-1)/2)+1
    if x % 2 != y % 2:
        i += d
    ans.append(str(i))
print("\n".join(ans))
