S = int(input())
M = 10**9
p = [0, 0, 1, M]
a, b = divmod(S, M)
print(a+1, M-b, *p)
