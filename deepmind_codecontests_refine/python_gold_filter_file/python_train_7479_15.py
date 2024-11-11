
def bitadd(a,w,bit): #aにwを加える(1-origin)

    x = a
    while x <= (len(bit)-1):
        bit[x] += w
        x += x & (-1 * x)

def bitsum(a,bit): #ind 0～aまでの和を求める

    ret = 0
    x = a
    while x > 0:
        ret += bit[x]
        x -= x & (-1 * x)
    return ret


N,K = map(int,input().split())

a = []

for i in range(N):

    A = int(input())
    a.append(A-K)


B = [0]

for i in range(N):

    B.append(B[-1] + a[i])

#print (B)
C = B.copy()
C.sort()

dic = {}

num = 1
for i in range(N+1):

    if i == 0:
        dic[C[i]] = num
        num += 1
    elif C[i] != C[i-1]:
        dic[C[i]] = num
        num += 1

for i in range(N+1):
    B[i] = dic[B[i]]

BIT = [0] * (len(B) + 1)

ans = 0

for i in range(N+1):

    ans += bitsum(B[i],BIT)
    bitadd(B[i],1,BIT)

print (ans)
    
