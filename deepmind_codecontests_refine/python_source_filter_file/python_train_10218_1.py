def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a%b)

def ways(l):
    return (n*k)//gcd((n*k), l)

def norm(x):
    if x%(n*k) == 0:
        return n
    return x%(n*k)

n, k = [int(i) for i in input().split()]
a, b = [int(i) for i in input().split()]

start = [norm(1-a), norm(1+a)]

ends = []
for i in range(n):
    rest = i*k + 1
    ends.append(norm(rest-b))
    ends.append(norm(rest+b))

lengths = []

def dist(a, b): # a to b
    if a <= b:
        return b-a
    else:
        return n*k - a + b

for i in range(len(ends)):
    lengths.append(dist(ends[i], start[0]))
    lengths.append(dist(ends[i], start[1]))

ans = []
for i in lengths:
    ans.append(ways(i))
print(min(ans), max(ans))
