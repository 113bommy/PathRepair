N=int(input())
*A, = map(int,input().split())
B = {}
for a in A: B[a] = B.get(a,0)+1
m = min(B)
M = max(B)
if m+1<M:
    print("No")
    exit()
def check(n):
    b0 = B.setdefault(n-1,0)
    b1 = B.setdefault(n,0)
    if b1==0:
        return b0==n
    else:
        return 1<= n-b0 <= b1//2
if m+1==M:
    ans = check(M)
else:
    ans = check(m) or check(m+1)
print("Yes" if ans else "No")