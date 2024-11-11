N, Y, Z = map(int, input().split())
As = list(map(int, input().split()))
dpx, dpy = [0]*(N-1), [0]*(N-1)
#dpx[i] = min(dpy[i+1]...dpy[N-2], abs(As[N-1]-As[i]))
#dpy[i] = max(dpx[i+1]...dpx[N-2], abs(As[N-1]-As[i]))
for i in range(N-2, -1, -1):
    mny, mxx = 10**10, 0
    for j in range(i+1, N-1):
        mny = min(mny, dpy[j])
        mxx = max(mxx, dpx[j])
    dpx[i] = max(mny, abs(As[N-1]-As[i]))
    dpy[i] = max(mxx, abs(As[N-1]-As[i]))
dpx.append(abs(As[N-1]-Z))
print(max(dpx))
