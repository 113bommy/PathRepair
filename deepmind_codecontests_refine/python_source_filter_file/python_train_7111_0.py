import sys
ints = (int(x) for x in sys.stdin.read().split())
sys.setrecursionlimit(3000)

def main():
    ntc = next(ints)
    for tc in range(1,ntc+1):
        a, b, c = (next(ints) for i in range(3))
        gcd = 10**(c-1)
        x = gcd*next(2**k for k in range(90) if len(str(2**k))==a)
        y = gcd*next(3**k for k in range(90) if len(str(3**k))==b)
        print(x, y)
    return

main()
