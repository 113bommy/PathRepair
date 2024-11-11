import math
inp = input().split(' ')
n, k = int(inp[0]), int(inp[1]) 
a = input()
a = list(a)
x = 1
cnt = [0] * 26
for i in range(1,n):
    if a[i] == a[i-1]:
        x += 1
    else:
        cnt[ord(a[i-1]) - ord('a')] += math.trunc(x/k)
        x = 1
cnt[ord(a[i-1]) - ord('a')] += math.trunc(x/k)
print(max(cnt))
    