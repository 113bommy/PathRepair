# -*- coding: utf-8 -*-
def inpl(): return list(map(int, input().split()))
"""
1 <= A, B <= 1659まで対応してるよ
"""
A, B = inpl()

L = [["."]*50 for i in range(100)]
R = [["#"]*50 for i in range(100)]

def plot(R):
    print("\n".join(["".join(r) for r in R]))

count = 0
for i in range(98):
    for j in range(16):
        if count == B-1:
            break
        L[i+1][j*3 + i%3 + 1] = "#"
        count += 1

count = 0
for i in range(98):
    for j in range(16):
        if count == A-1:
            break
        R[i+1][j*3 + i%3 + 1] = "."
        count += 1
        
ANS = [l+r for l, r in zip(L, R)]

print(100, 100)
plot(ANS)
