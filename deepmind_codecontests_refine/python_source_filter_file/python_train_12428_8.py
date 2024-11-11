n = int(input())
t = list(map(int, input().split()))
t.sort()
s = 0
for i in range(n):
    s += abs(t[i] - i)
print(s)