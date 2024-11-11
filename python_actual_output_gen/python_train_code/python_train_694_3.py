n = int(input())
m = int(input())
a = [int(input()) for i in range(n)]
a1 = max((sum(a) + m) // n, max(a))
print(a1, m + max(a))