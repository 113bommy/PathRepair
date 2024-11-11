def dist(x):
    return ((x - u) ** 2 + v * v) ** .5
n, a, b = map(int, input().split())
*x, = map(int, input().split())
u, v = map(int, input().split())
min_d = min_t = 1e9
min_ind = 0
for i in range(1, n):
    d = dist(x[i])
    tmp = x[i] / a + d / b
    if min_t > tmp or min_t == tmp and min_d > d:
        min_ind, min_d, min_t = i + 1, d,tmp
print(min_ind)