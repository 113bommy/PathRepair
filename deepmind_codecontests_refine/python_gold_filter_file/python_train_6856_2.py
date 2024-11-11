N = int(input())
for i in range(10000):
    if i * (i+1) // 2 >= N:
        k = i
        break

while N:
    if N <= k:
        print(N)
        break
    N -= k
    print(k)
    k -= 1