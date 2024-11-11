import sys

def main():
    n, *s = sys.stdin.read().strip().split('\n')
    c, t = 0, [(-1, 1), (-1, -1), (1, 1), (1, -1), (0, 0)]
    for i in range(1, int(n)-1):
        for j in range(1, int(n)-1):
            c += all(s[i+m][j+n] == 'X' for m,n in t)
    return c
    
print(main())
