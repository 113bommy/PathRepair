n = int(input())
a = [int(x)%2 for x in input().split()]
ans = min(a.count(1),a.count(1))
print(ans)
