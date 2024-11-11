n = int(input())
t = 0
for i in range(n):
    l, r = map(int, input().split())
    t += r-l+1
print(t)