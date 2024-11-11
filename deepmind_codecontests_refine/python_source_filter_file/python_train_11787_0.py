import sys

n, *x = map(int, sys.stdin.read().split())
x.sort()

def main():
    res1 = set()
    for i in x:
        if not i-1 in res1:
            res1.add(i-1)
        elif not i in res1:
            res1.add(i)
        elif not i+1 in res1:
            res1.add(i+1)
        else:
            continue
    
    res2 = set()
    for i in x:
        if i-1 in res2:
            res2.add(i-1)
        if i in res2:
            res2.add(i)
        elif i+1 in res2:
            res2.add(i+1)
        else:
            res2.add(i+1)
    
    return len(res2), len(res1)

if __name__ == '__main__':
    ans = main()
    print(*ans, sep=' ')