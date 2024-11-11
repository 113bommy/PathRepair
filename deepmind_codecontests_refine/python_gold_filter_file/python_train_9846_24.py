N = int(input())
array = list(map(int, input().split()))
maxs = max(array)
ans = 0
for i in array:
    ans += maxs - i
print(ans)