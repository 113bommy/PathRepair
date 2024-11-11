import sys
input = sys.stdin.readline
n = int(input())
A = list(map(int,input().split()))
ANS0 = []
ANS1 = []

if n == 1:
    print(1,1)
    print(1)
    print(1,1)
    print(1)
    print(1,1)
    print(-A[0]-2)
else:
    nm = n-1
    for i in range(nm):
        ANS0.append(nm * (A[i] % n))
    for i in range(nm):
        ANS1.append(-(A[i] + ANS0[i]))
    ANS1.append(0)

    print(1, nm)
    print(*ANS0)
    print(1, n)
    print(*ANS1)
    print(nm, n)
    print(-A[nm])