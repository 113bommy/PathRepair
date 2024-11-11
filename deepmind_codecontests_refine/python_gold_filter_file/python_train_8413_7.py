import sys
input = sys.stdin.readline
Q = int(input())
AB = [list(map(int,input().split())) for i in range(Q)]

small_case = {(1,1):0, (1,2):0}
for A,B in AB:
    M = A*B
    A,B = sorted([A,B])
    if (A,B) in small_case:
        print(small_case[(A,B)])
        continue
    ans = 0
    i = 1
    b = int(pow(M,0.5))
    if b == B:
        b -= 1
    ans += (M-1)//b - A
    ans += b-1
    ans += A-1
    print(ans)
