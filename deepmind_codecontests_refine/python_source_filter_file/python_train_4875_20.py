n, m = map(int, input().split())
SG = sorted([[int(i) for i in input().split()] for i in range(m)], key = lambda x: x[1])

cnt = 1
b = SG[0][1]
for s, g in SG[1:]:
    if s >= b:
        b = s + 1
        cnt += 1
        
print(cnt)