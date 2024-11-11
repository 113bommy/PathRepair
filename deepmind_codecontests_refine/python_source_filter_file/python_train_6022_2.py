import bisect
N = int(input())
A = sorted(list(map(int, input().split())))
B = sorted(list(map(int, input().split())))
C = sorted(list(map(int, input().split())))
ali = [0] * (N+1)
bli = [N - bisect.bisect_left(C,B[i]) for i in range(N)]
for i in range(N):
    ali[i+1] = ali[i] + bli[i]
print(sum([ali[N]-ali[bisect.bisect_left(B,A[i])] for i in range(N)]))