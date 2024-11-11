N = int(input())
K = int(input())
a = 1
for _ in range(N):
    a = min(a*2, a+k)
print(a)