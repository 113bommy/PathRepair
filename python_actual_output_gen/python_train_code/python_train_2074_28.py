def check(i, N, M, V, P, A):
    K = N - V
    tot = sum(A[(P-1):i]) - A[i]*(i-(P-1))
    if K*M >= tot and (A[P-1]-A[i])<=N:
        return True
    else:
        return False

N, M, V, P = map(int,input().split())
A = [int(i) for i in input().split()]
A.sort(reverse=True)

start = P
end = N-1
if check(end, N, M, V, P, A):
    print(N)
elif not check(start, N, M, V, P, A):
    print(P)
else:
    while True:
        if (end - start) == 1:
            break
        new = (start + end)//2
        flag = check(new, N, M, V, P, A)
        if flag:
            start = new
        else:
            end = new
    print(start+1)
        