from collections import Counter,defaultdict,deque
read = lambda : list(map(int,input().split()))

def solve():
    pass

n,k = read()
cnt = n
start = 1
for i in range(1+k,1+2*k+1):
    val = (n-i) % (1+2*k)
    if 1+k <= val < 1+2*k or val == 0:
        c = 1 + (n-i) // (1+2*k) + (val != 0)
        if c < cnt:
            cnt = c
            start = i - k

res = []
while start < n+1:
    res.append(start)
    start += 1+2*k
print(cnt)
print(' '.join(map(str,res)))