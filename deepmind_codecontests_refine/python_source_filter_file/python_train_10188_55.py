N = int(input())
p = list(map(int, input().split()))
a = [0]*N
b = [0]*N

for i in range(N):
    c = 4999
    a[p[i]-1] = c*p[i]
    b[p[i]-1] = i + 1 - c*p[i]

m = min(b)
b = map(lambda x: x-m+1,b)
print(" ".join(map(str,a)))
print(" ".join(map(str,b)))
