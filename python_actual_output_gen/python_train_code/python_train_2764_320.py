n = int(input())
a = list(map(int,input().split()))
r = 1
for i in range(n):
    r += a[i]
print(float(r / len(a)))