t = int(input())
def is_ok(A,h,k):
    cnt = 0
    for i in range(len(A)):
        if i == len(A)-1:
            cnt += k
        else:
            if A[i] + k -1 >= A[i+1]:
                cnt += A[i+1] - A[i]
            else:
                cnt += k
    if cnt >= h:
        return True
    else:
        return False


def solve(n,h,A):
    ng = 0
    ok = 10 ** 9
    while ok - ng > 1:
        k = (ng+ok)//2
        if is_ok(A,h,k):
            ok = k
        else:
            ng = k
    return ok

ans = []
for _ in range(t):
    n,h = map(int,input().split())
    A = list(map(int,input().split()))
    ans.append(solve(n,h,A))
for a in ans:
    print(a)