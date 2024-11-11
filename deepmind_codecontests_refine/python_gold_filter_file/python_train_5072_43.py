#!/usr/bin/env python3

def count(o):
    ans = 0
    for i in o:
        if i % 2 == 0:
            ans += 1
        else:
            ans -= 1
    if ans == 0:
        return True
    else:
        return False

N, B = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]

ans = []
for i in range(1, len(x)):
    if count(x[:i]) and count(x[i:]):
        ans.append(abs(x[i] - x[i - 1]))
otvet = 0
if len(ans) > 0:
    while True :
        B -= min(ans)
        if B < 0:
            break
        ans[ans.index(min(ans))] = 1000
        otvet += 1
print(otvet)



