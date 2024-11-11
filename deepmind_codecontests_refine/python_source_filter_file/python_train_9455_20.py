n = int(input())
A = list(map(int, input().split()))
p = max(A)
q = p
for a in A:
    if abs(p/2-a) < abs(p/2-q): q = a
print(p, q)