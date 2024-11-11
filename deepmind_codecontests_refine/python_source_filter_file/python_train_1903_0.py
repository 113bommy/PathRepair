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

def solve(a, n, l):
    p = []
    for i in range(n):
        if(l[i] == 0):
            p += [a[i]]
    p = sorted(p, reverse = True)
    for i in range(n):
        if(l[i] == 0):
            a[i] = p.pop()
    return a
def main():
    t = int(get())
    ans = []
    for i in range(t):
        n = int(get())
        a = getf()
        l = getf()
        putf(solve(a, n, l))
main()
