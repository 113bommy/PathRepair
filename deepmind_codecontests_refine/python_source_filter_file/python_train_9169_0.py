input()
n = list(map(int, input().split()))
f = 0
for i in n:
    if n.count(i) > f:
        f = i
print(f)
