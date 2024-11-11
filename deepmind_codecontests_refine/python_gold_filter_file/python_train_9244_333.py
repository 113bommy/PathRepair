n = int(input())
t = [int(input()) for _ in range(5)]
m = min(t)
print((n+m-1)//m+4)