n, m, k = map(int, input().split())
p = list(map(int, input().split()))
pos = 0
ans = 0
i = 0
while i < m:
    curr_s = (p[i] - 1 - pos) // k + 1
    j = i + 1
    while j < m:
        if (p[j] - 1 - pos) // k + 1 == curr_s:
            j += 1
        else:
            break
    pos += j - i
    i = j
    ans += 1
print(ans)