import sys
import math

def input():
    return sys.stdin.readline().strip()

def iinput():
    return [int(x) for x in sys.stdin.readline().split()]

def vxod(q):
    return q * (q + 1) // 2

def main():
    n, m = iinput()
    if n - m >= m + 1:
        grupps = (n - m) // (m + 1)
        grupps_1 = (n - m) % grupps
        grupps_2 = m + 1 - grupps_1
        summ = grupps_1 * vxod(grupps + 1) + grupps_2 * vxod(grupps)
        print(vxod(n) - summ)
    else:
        print(vxod(n) + m - n)
    return

for qwerty in range(int(input())):
    main()
