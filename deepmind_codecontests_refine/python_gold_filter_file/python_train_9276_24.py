import sys

def main():
    inp = sys.stdin.read().strip().split('\n')
    return set.intersection(*(set(i.split()[1:]) for i in inp[1:]))
    
print(*main())

