from sys import stdin, stdout
import math

def main():
    n,m = list(map(int, stdin.readline().split()))
    a = list(map(int, stdin.readline().split()))
    b = list(map(int, stdin.readline().split()))
    min_a = min(a)
    gcd_a = -1
    for x in a:
        if x == min_a:
            continue
        if gcd_a == -1:
            gcd_a = x - min_a
            continue
        gcd_a = math.gcd(gcd_a, x - min_a)
        if gcd_a == 1:
            break
    ans = []
    for y in b:
        if n == 1:
            ans.append(str(a[0] + y))
        else:
            ans.append(str(math.gcd(gcd_a, min_a + y)))
    print(" ".join(ans))

main()