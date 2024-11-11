n, m, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

for i in range(n):
    a[i] = [a[i],i]


num_required = m * k
a.sort()
candidate = a[n - num_required:n]
len_cand = len(candidate)
beauty = 0
for x in range(len_cand):
    beauty += candidate[x][0]
    candidate[x][0], candidate[x][1] = candidate[x][1], candidate[x][0]

print(beauty)
candidate.sort()

ans = []
for x in range(m - 1, len_cand - 1, m):
    ans.append(str(candidate[x][0] + 1))


print(' '.join(ans))