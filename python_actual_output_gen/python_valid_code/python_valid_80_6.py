n, m, r = map(int, input().split())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))
a = min(l1)
b = max(l2)
if a < b:
    q = r // min(l1)
    w = q * b
    print((r - a * q) + w)
elif a > b:
    print(r)
    