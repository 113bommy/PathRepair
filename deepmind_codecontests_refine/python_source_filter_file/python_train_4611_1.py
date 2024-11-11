
from sys import stdin
from itertools import repeat
def main():
    n = int(stdin.readline())
    p = list(map(int, stdin.readline().split(), repeat(10, n - 1)))
    a = list(map(int, stdin.readline().split(), repeat(10, n)))
    l = [1] * n
    b = [0] * n
    ans = 0
    for i in range(n - 1, -1, -1):
        b[i] += l[i]
        x, y = divmod(a[i], b[i])
        print(x,y)
        if y:
            x += 1
        if ans < x:
            ans = x
        if i:
            x = p[i-1] - 1
            a[x] += a[i]
            l[x] = 0
            b[x] += b[i]
    print (ans)
main()
