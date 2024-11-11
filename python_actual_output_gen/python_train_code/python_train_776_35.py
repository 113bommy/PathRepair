n, m = map(int,input().split())

f = list(map(int,input().split()))

f.sort()

min_delta = f[m-1] - f[0]

for i in range(m-n):
    current_delta =  f[i+n-1] - f[i]
    if current_delta < min_delta:
        min_delta = current_delta

print(min_delta)
