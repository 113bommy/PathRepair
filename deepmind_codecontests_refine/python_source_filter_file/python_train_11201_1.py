def func(old, new):
    for o, n in zip(old, new):
        if(o != n):
            return "rated"
    if(old == sorted(old)):
        return "maybe"
    return "unrated"

n = int(input())
old = []
new = []
for _ in range(n):
    o, n = map(int, input().split())
    old.append(o)
    new.append(n)
print(func(old, new))