n = int(input())
l = list(map(int, input().split()))
l.sort()
m = [0] * 200000

for i in range(n - 1):
    for j in range(i + 1, n):
        m[l[i] + l[j]] += 1
 
print(max(m))