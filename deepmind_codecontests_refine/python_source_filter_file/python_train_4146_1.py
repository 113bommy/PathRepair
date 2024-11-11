N = int(input())
A = list(map(int,input().split(" ")))
A.sort()
used = [0] * N
pow2_set = reversed([ 1<<i for i in range(25)])
ans = 0
for pow2 in pow2_set:
    l,r = 0,N-1
    while l < r:
        if A[l] + A[r] < pow2:
            l += 1
        elif A[l] + A[r] == pow2:
            if used[l] == 0 and used[r] == 0:
                ans += 1
                used[l],used[r] = 1,1
            else:
                if used[l] == 1:
                    l += 1
                if used[r] == 1:
                    r -= 1
        else:
            r -= 1

print(ans)