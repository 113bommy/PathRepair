L = int(input())

k = L.bit_length()
ans = []
for i in range(1, k):
    ans.append([i,i+1,0])
    ans.append([i,i+1,1<<(k-i-1)])

for i in range(1,k-1):
    if L & 1<<i:
        mask = (1<<(k+1)) - (1<<(i+1))
        w = L & mask
        ans.append([1, k-1-i, w])

print(k, len(ans))
for i in ans:
    print(*i)