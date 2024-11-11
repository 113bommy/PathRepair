n, x = map(int, input().split())
mlook = 0
available = [0]*x
mex = -1
ans=[0]*n
for _ in range(n):
    num = int(input())
    if num == mex+1 or mlook == num % x:
        mex += 1
        mlook = (mlook+1) % x
        while available[mlook] > 0:
            available[mlook] -= 1
            mex += 1
            mlook = (mlook+1) % x
    else:
        available[num % x] += 1
    ans[_] = mex+1

print("\n".join(str(ans[k]) for k in range(n)))