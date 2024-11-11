n = int(input())


i = 1
k = 1
for j in range(n-1):
    i += k
    if i % n == 0:
        print(i, end=" ")
    else:
        print(i % n, end=" ")
    k += 1
