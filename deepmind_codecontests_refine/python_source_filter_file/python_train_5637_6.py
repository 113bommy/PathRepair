n = int(input())
m = list(map(int, input().split()))
m.sort()
l = [0] * 200000

for i in range(n - 1):
    for j in range(i + 1, n):
        l[l[i] + l[j]] += 1
 
print(max(l))