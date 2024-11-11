import sys

n = int(input())
mr = 0
cr = 0
for i in range(n):
    m, c = map(int, sys.stdin.readline().split())
    if m > c:
        mr += 1
    elif c > m:
        cr += 1

if mr > cr:
    print("Mishka")
elif cr > mr:
    print("Chris")
else:
    print("Friendship is magic!^^")
