a, b = map(int, input().split())
ans = ["Even", "Odd"]
print(ans[(a + b) % 2])
