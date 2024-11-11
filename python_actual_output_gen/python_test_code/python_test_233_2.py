R = lambda: map(int, input().split())
n, k = R()
arr = sorted(list(R()))
s = set(arr)
if k == 1:
    print(1)
else:
    for x in arr:
        if x in s and x * k in s:
            s.remove(x * k)
    print(len(s))