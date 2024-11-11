n = int(input())
#n, m = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
m = min(c)
l = -1
x = 0
for i in range(n):
    if c[i] == m:
        if l != -1:
            x = max(x, i - l)
        l = i
print(x)