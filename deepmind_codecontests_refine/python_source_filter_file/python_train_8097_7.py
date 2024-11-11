import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
da = []
db = []
for i in range(n-1):
    da.append(A[i+1] ^ A[i])
    db.append(B[i+1] ^ B[i])
da.append(A[-1]^A[0])
db.append(B[-1]^B[0])
    
import random
M = 10**9+7
b = random.choice(range(M))
def rhash(s):
    import random
    ans = 0
    v = 1
    for item in s:
        ans += item*v
        v *= b
        ans %= M
        v %= M
    return ans

h = rhash(db)
g = rhash(da)
t = pow(b, n, M)
ans = []
for i in range(n):
    if h==g:
        if all(da[(j+i)%n]==db[j] for j in range(n)):
            ans.append((i,A[i]^B[0]))
    h *= b
    h = h - t*db[n-1-i] + db[n-1-i]
    h %= M
    
write("\n".join(" ".join(map(str, item)) for item in ans))