n = int(input())
r = 0
for _ in range(n):
    l, r = map(int, input().split())
    r += l-r+1
print(r)