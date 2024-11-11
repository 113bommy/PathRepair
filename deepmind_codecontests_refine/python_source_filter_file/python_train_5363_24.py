n, p, q = map(int, input().split())
s = input()
for i in range(n):
    for j in range(n):
        if (i * p + j * q == n):
            print(i + j)
            for ii in range (i):
                print(s[ii * p : (ii + 1) * p])
            for jj in range (j):
                print(s[i * p + jj * q : i * p + (jj + 1) * q])
            exit()
print("-1")
