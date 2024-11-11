import math

n, k = map(int, input().split())

def getMin(n):
    count = 0
    while n:
        count += 1
        d = int(math.log(n, 2))
        n -= math.pow(2, d)
    return count

def getSeq(n, k):
    if n==k:
        return [1]*k
    seq = []
    if k==0:
        return seq
    d = int(math.log(n, 2))
    print('n,k %s %s'%(n,k))
    for i in range(d, -1, -1):
        # print(i)
        x = int(math.pow(2, i))
        a, b = 1, n-x
        # print('a,b %s %s'%(a,b))
        if a + b < k:
            continue
        else:
            seq += [x]
            seq += getSeq(n-x, k-1)
            return seq
    return seq

def sol(n, k):
    MAX = n
    MIN = getMin(n)
    if k>MAX or k<MIN:
        return "NO"
    else:
        seq = getSeq(n, k)
        seq_new = [str(x) for x in seq]
        return "YES\n%s"%(' '.join(seq_new))

print(sol(n, k))
    