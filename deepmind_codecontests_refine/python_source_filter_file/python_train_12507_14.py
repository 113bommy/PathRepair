import sys

def main():
    inp = sys.stdin.read().strip().split('\n')
    p = int(inp[-1]) - 1
    n = int(inp[0])
    for i in range(1, n+1):
        x, y = map(int, inp[i].split())
        if x <= p < y: return n + 1 - i

print(main())
