m, n = map(int,input().split())
a=set()
for _ in range(m):
    a.update(input().split()[1:])
print(["NO","YES"][len(a)==n])