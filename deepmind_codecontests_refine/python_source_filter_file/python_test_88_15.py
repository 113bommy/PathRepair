import sys
from os import path
 
if(path.exists('input.txt')):
    sys.stdout = open('output.txt', 'w')
    sys.stdin = open('input.txt', 'r')
 
 
def main():
    inp = [x for x in sys.stdin.buffer.read().split()]
    ii = 0
    out = []
 
    t = int(inp[ii])
    ii += 1
    for _ in range(t):
 
        n = int(inp[ii])
        ii += 1
        arr = inp[ii:ii+n]
        ii += n
 
        if n % 2 == 0:
            out.append("YES")
            continue
 
        flag = False
        for i in range(n-1):
            if arr[i] >= arr[i+1]:
                flag = True
                break
 
        if flag:
            out.append("YES")
        else:
            out.append("NO")
 
        pass
 
    out_str = "\n".join(str(x) for x in out)
    sys.stdout.write(out_str)
 
 
main()