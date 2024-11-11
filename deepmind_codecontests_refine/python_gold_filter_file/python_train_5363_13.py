
n, p, q = map(int, input().split())
s = input()

for i in range(n//p + 1):
    if (n - i * p) % q == 0:
        ii = (n - i * p) // q
        print(i+ii)
        for j in range(i):
            print(s[j*p:j*p+p])
        for j in range(ii):
            print(s[i*p+j*q:i*p+j*q+q])
        import sys
        sys.exit()

print(-1)
