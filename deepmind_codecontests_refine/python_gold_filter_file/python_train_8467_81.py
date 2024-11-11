import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s); sys.stdout.write('\n')
def wi(n): sys.stdout.write(str(n)); sys.stdout.write('\n')
def wia(a, sep=' '): sys.stdout.write(sep.join([str(x) for x in a])); sys.stdout.write('\n')
 

def main():
    n = ri()
    if n == 0:
        wia([0, 0, 0])
        return
    
    f = [0, 1]
    while True:
        x = f[-1] + f[-2]
        if x == n:
            break
        f.append(x)
        
    wia([0, f[-2], f[-1]])    
 
if __name__ == '__main__':
    main()