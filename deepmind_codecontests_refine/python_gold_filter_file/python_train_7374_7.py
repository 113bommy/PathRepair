N = int(input())
m = 0
for i in range(N):
    l, r = map(int, input().split())
    m += r-l+1
print(m)
