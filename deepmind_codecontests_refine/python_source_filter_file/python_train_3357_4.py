t = int(input())
for i in range(t):
    n, k = input().split()
    n, k = int(n), int(k)
    need = (k-1)/(n-1)
    print(round(k+need))