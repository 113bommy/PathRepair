import sys
 
# inf = open('input.txt', 'r')
# reader = (line.rstrip() for line in inf)
reader = (line.rstrip() for line in sys.stdin)
input = reader.__next__
 
class SegmTree():
    '''
    - modify single element
    - get min on interval
    '''
    def __init__(self, size):
        N = 1
        while N < size:
            N <<= 1
        self.N = N
        self.tree = [(float('inf'), -1)] * (2*self.N)
        
    def build(self):
        for i in range(self.N - 1, 0, -1):
            self.tree[i] = min(self.tree[i<<1], self.tree[i<<1|1])
 
    def modify(self, i, value):
        i += self.N
        self.tree[i] = (value, i - self.N)
        while i > 1:
            self.tree[i>>1] = min(self.tree[i], self.tree[i^1])
            i >>= 1
 
    def query_range(self, l, r):
        l += self.N
        r += self.N
        result = (float('inf'), -1)
        while l < r:
            if l & 1:
                result = min(result, self.tree[l])
                l += 1
            if r & 1:
                r -= 1
                result = min(result, self.tree[r])
            l >>= 1
            r >>= 1
        return result
 
n = int(input())
a = list(map(int, input().split()))
if n < 6:
    print(max(a) - min(a), 1)
    ans = [1] * n
    print(*ans)
    sys.exit()

pos = {}
for i, val in enumerate(a):
    if val not in pos:
        pos[val] = []
    pos[val].append(i)
    
a.sort()
jump = []
for i in range(n - 1):
    jump.append(a[i + 1] - a[i])
totalSum = a[-1] - a[0]
 
# st[i] - min "variety" if i - last separation
st = SegmTree(n - 1)
 
for i in range(2, min(5, n-1)):
    st.modify(i, totalSum - jump[i])
 
prevSep = [-1] * (n-1)
for i in range(5, (n - 1) - 2):
    leftMin, sep = st.query_range(2, i - 2)
    newVal = leftMin - jump[i]
    prevSep[i] = sep
    st.modify(i, newVal)
 
res, sep = st.tree[1]
seps = []
while sep > -1:
    seps.append(sep)
    sep = prevSep[sep]
team = 1
ans = [None] * n
for i, val in enumerate(a):
    p = pos[val].pop()
    ans[p] = team
    if seps and i == seps[-1]:
        team += 1
        seps.pop()
    
print(res, team)
print(*ans)
 
# inf.close()