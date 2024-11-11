n = int(input())
a = list(map(int, input().split()))
a = [0] + a
for i in range(n):
    if a[i+1] == a[i]:
        a[i] = -1
print(a.count(-1))