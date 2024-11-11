n = int(input())
a = set(map, input().split())
ans = len(a) if len(a)%2 == n%2 else len(a)-1
print(ans)