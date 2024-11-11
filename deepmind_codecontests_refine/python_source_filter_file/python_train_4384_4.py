import sys

def main():
    w, h, k = map(int, sys.stdin.read().strip().split())
    return sum(2*(w + h - i*4 - 2) for i in range(k))
    
print(main())
