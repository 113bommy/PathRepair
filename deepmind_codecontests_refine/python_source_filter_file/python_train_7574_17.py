import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s); sys.stdout.write('\n')
def wi(n): sys.stdout.write(str(n)); sys.stdout.write('\n')
def wia(a, sep=' '): sys.stdout.write(sep.join([str(x) for x in a])); sys.stdout.write('\n')
 
 
def main():
    n = ri()
    s = rs()
    for d in range(1, n+1):
        if n % d > 0:
            continue
        s = s[d::-1] + s[d+1:]         
    ws(s)
 
if __name__ == '__main__':
    main()