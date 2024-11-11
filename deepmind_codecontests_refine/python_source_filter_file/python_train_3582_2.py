#!/usr/bin/python3

def readln(): return tuple(map(int, input().split()))

n, = readln()
b = readln()
cnt = [0] * 101
for v in b:
    cnt[v] += 1
f = []
s = []
x = []
y = []
for i in range(10, 101):
    if cnt[i] > 1:
        f.extend([i] * (cnt[i] // 2))
        s.extend([i] * (cnt[i] // 2))
        if cnt[i] % 2:
            y.append(i)
        cnt[i] = 0
    elif cnt[i] == 1:
        x.append(i)
f.extend(x[:len(x)//2])
f.extend(y[:n - len(f)])
s.extend(x[len(x)//2:])
if len(s) < n:
    s.extend(y[n - len(s):])
print(len(set(f)) * len(set(s)));
ans = [1] * 2 * n
for v in s:
    for i in range(2 * n):
        if b[i] == v and ans[i] == 1:
            ans[i] = 2
            break
print(*ans)
