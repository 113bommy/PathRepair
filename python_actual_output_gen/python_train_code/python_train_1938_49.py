n, a, b, c = map(int, input().split())
mn = 999999999999999
for x in range(4, 104, 4):
    if x >= n % 100:
        k = x-(n%100)

        for i in range(k+1):
            for j in range(k//2+1):
                for m in range(k//3+1):
                    # print(i, j, k)
                    if i+2*j+3*m == k:
                        val = i*a + j*b + m*c
                        if val < mn:
                            mn = val
print(mn)
