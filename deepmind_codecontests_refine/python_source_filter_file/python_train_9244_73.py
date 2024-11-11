n = int(input())
a = [int(input()) for i in range(n)]
print(-(-n // min(a)) + 4)