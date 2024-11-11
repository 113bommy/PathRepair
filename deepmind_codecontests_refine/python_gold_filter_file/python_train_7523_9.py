from sys import stdout
from sys import stdin
def get():
    return stdin.readline().strip()
def getf():
    return [int(i) for i in get().split()]
def put(a, end = "\n"):
    stdout.write(str(a) + end)
def putf(a, sep = " ", end = "\n"):
    stdout.write(sep.join([str(i) for i in a]) + end)

def solve(a, n):
    pr = [0]
    for i in range(n):
        pr.append(pr[-1] + a[i])
    hv = set()
    ans = 0
    d = dict()
    last_change = n + 1
    for i in range(n, -1, -1):
        v = pr[i]
        if(v in hv):
            if(d[v] < last_change):
                ans += 1
                last_change = i + 2
        else:
            hv.add(v)
        d[v] = i
    return ans

def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    print(min(solve(a, n), solve(a[ :: - 1], n)))
main()
