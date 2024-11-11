import sys

INF = 1000000007

stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def nal(): return list(map(int, stdin.readline().split()))
def ns(): return stdin.readline().strip()
def ni(): return int(stdin.readline())

N = ni()
x = nal()
x.insert(0, 0)

n = 1
c = 0
a = 1

for i in range(N):
    t = x[i+1] - x[i] - 1
    c = c+1
    if(t > 1):
        n = n+t-1
    elif(t == 0):
        n = n-1
        if(n == -1):
            n = 1
            a = a*c%INF
            c = c-1

for i in range(1, c+1):
    a = a*i%INF

print(a % INF)