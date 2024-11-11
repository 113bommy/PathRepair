n, p = map(int, input().split())
t, q = input(), 'NO'
if p == 2:
    if t == 'a': q = 'b'
    elif t == 'ab': q = 'ba'
elif p > 2: 
    t = [ord(c) - 97 for c in t] + [27, 27]
    for k in range(n - 1, -1, -1):
        for i in range(t[k] + 1, p):
            if i - t[k - 1] and i - t[k - 2]:
                t[k] = i
                a, b = min(t[k - 1], 2), min(t[k], 2)
                if a == b: a = 1
                t = t[: k + 1] + [3 - a - b, a, b] * (n // 3 + 1)
                print(''.join(chr(t[i] + 97) for i in range(n)))
                exit(0)
print(q)