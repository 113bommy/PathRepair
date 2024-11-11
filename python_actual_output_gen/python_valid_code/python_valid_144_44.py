n, c = map(int, input().split())
N = [int(i) for i in input().split()]
a = 0
for i in range(1, n):
    if N[i] - N[i-1] <= c:
        a+= 1
    else:
        a = 1
print(a)