N = int(input())
mins = []
maxs = []
for i in range(3):
    mi, ma = map(int, input().split())
    mins.append(mi)
    maxs.append(ma)
anss = list(mins)
rem = N - sum(anss)

for i in range(2, -1, -1):
    if rem >= 0:
        add = min(rem, maxs[i] - mins[i])
        rem -= add
        anss[i] += add
print(" ".join(map(str, anss)))
