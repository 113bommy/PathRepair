n, p, k = map(int, input().split())
z = []
if p-k > 1:
    z.append('<<')
for i in range(max(p-k, 1), min(p+k, n)+1):
    if i == p:
        z.append('('+str(i)+')')
    else:
        z.append(str(i))
if p-k < n:
    z.append('>>')
print(*z)
