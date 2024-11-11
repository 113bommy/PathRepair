n = int(input())
codes = [input() for i in range(n)]
def dist(w1, w2):
    assert len(w1) == len(w2)
    d = 0
    for i in range(len(w1)):
        if w1[i] != w2[i]: d += 1
    return max(0, (d-1)//2)
d = 6
for i in range(n):
    for j in range(i+1, n):
        d = min(d, dist(codes[i], codes[j]))
print(d)
