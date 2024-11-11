s = input()
k = int(input())
if k > len(s):
    print("impossible")
else:
    n = 0
    for c in s:
        n += 1 / s.count(c)
    n = round(n)
    if n > k:
        n = k
    print(k - n)