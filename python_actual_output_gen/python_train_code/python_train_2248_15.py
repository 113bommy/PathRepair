n, m = map(int, input().split())
works = list(map(int, input().split()))
ans = 0
current_home = 1
for i in works:
    ans += current_home - 1 + i - 1 if current_home > i else i - current_home
    current_home = i
print(ans)