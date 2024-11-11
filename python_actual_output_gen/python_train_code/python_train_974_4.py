N = int(input())
d = map(int, input().split())
d_2 = map(lambda x: x*x, d)
print((sum(d)**2 - sum(d_2)) // 2)