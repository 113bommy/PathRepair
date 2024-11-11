a, b, c = map(int, input().split())
ans = 'Yes' if b-a == c-b else 'No'
print(ans)