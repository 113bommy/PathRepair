s = input()
t = input()
a = [int(x) - 1 for x in input().split()]

def ok(n):
    bad = set(a[:n])
    it = (a for i, a in enumerate(s) if i not in bad)
    return all(c in it for c in t)

low = 0
high = len(s)
while low < high:
    mid = (high + low) // 2
    if (ok(mid)):
        low = mid + 1
    else:
        high = mid - 1
print (high)
