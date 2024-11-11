a, b = map(int, input().split())
ans = a*b if a<=9 and b<=9 else -1
print(ans)