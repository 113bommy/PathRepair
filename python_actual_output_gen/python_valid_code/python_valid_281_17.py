# import os


n, m = map(int, input().split())

s_n = input().split()
s_m = input().split()

t = int(input())

for _ in range(t):
    y = int(input())

    print(s_n[y%len(s_n)] + s_m[y%len(s_m)])


# 04/01 - 21
# 05/01 - 27
# 06/01 - 28