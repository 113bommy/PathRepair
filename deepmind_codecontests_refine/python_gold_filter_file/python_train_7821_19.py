n = int(input())
m = list(map(int, input().split()))
for i in range(n-1, 0, -1):
    #print(m[i-1], m[i])
    if m[i] == 1:
        m = m[i:]
        break
    if m[i] <= m[i-1]:
        m[i-1] = max(m[i] - 1, 0)

print(sum(m))
        
