n, m = map(int, input().split())

tree = [0 for _ in range(n+1)]
for _i in range(m):
    a, b = map(int, input().split())
    tree[a] += 1
    tree[b] += 1
if all(i%2==0 for i in tree):
    print("Yes")
else:
    print("No")