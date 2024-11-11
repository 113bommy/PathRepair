n = int(input())
n2 = n // 2
p = list(map(int, input().split()))
d = [0] * n
for i, v in enumerate(p):
    d[v-1] = i
    
r = []

def sw(i, j):
    r.append((i+1, j+1))

def swap(i, j):
    if i == j:
        pass
    elif abs(i-j) >= n2:
        sw(i,j)
        p[j] = p[j]
    else:
        ti = n-1 if i < n2 else 0
        tj = n-1 if j < n2 else 0
        sw(i, ti)
        if ti != tj: sw(ti, tj)
        sw(tj, j)
        if ti != tj: sw(ti, tj)
        sw(i, ti)
        p[j] = p[i]

for i, v in enumerate(p):
    j = d[i]
    swap(i, j)
    d[v-1] = j

print(len(r))
print("\n".join(f"{a} {b}" for a, b in r))
