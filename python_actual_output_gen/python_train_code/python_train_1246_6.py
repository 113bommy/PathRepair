N=int(input())
A=list(map(int,input().strip().split()))
B=list(map(int,input().strip().split()))
B.sort()
if sum(A)>=B[N-1]+B[N-2]:
    print('YES')
else:
    print('NO')
