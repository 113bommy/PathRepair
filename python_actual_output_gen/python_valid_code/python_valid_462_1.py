import sys
import io, os
input = sys.stdin.buffer.readline
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    A = list(map(int, input().split()))
    B = [10**a for a in A]
    cur_max = B[0]*k
    for i in range(1, n):
        a = A[i]
        b = B[i]
        y = B[i]-1
        cnt = 0
        for j in reversed(range(i)):
            q, r = divmod(y, B[j])
            cnt += q
            y = r
        if cnt >= k:
            ans = cur_max+1
            break
        else:
            cur_max = (k-cnt+1)*B[i]+B[i]-2
    else:
        print(cur_max+1)
        continue
    print(ans)
