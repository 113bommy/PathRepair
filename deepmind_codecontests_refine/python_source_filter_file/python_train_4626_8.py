n = int(input())
cnt = [1] * 100
x, y = map(int, input().split())
for i in range(n-1):
    l, r = map(int, input().split())
    cnt = cnt[:l] + [0] * (r-l) + cnt[r+1:]
print(sum(cnt[x:y]))
