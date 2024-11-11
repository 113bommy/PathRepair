n = int(input())
a = [int(input()) for i in range(5)]
ans = 0
print(-(-n // min(a)) + 4)