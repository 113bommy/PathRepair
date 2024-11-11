n = int(input())
l = [int(input()) for _ in range(5)]
ans = 0 - -n//min(l) + 4
print(ans)