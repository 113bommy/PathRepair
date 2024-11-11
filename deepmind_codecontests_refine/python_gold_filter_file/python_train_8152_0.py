import sys
input = sys.stdin.readline
for _ in range(int(input())):
    emp = input()
    xa,ya = map(int,input().split())
    xb, yb = map(int, input().split())
    xf, yf = map(int, input().split())

    ans = abs(xa-xb)+abs(ya-yb)
    if xa == xb and xa == xf and yf > min(ya,yb) and yf < max(ya,yb):
        ans += 2

    if ya == yb and yb == yf and xf > min(xa,xb) and xf < max(xa,xb):
        ans += 2

    sys.stdout.write(str(ans)+"\n")