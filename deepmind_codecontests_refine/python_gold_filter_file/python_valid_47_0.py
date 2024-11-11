## IO starts (Thanks pajenegod)

from sys import stdout
import os

ii = 0
_inp = b""

def getchar():
    global ii,_inp
    if ii >= len(_inp):
        _inp = os.read(0,4096)
        ii = 0
    if not _inp:
        return b" "[0]
    ii += 1
    return _inp[ii-1]

def input():
    c = getchar()
    if c == b"-"[0]:
        x = 0
        sign = 1
    else:
        x = c-b"0"[0]
        sign = 0
    c = getchar()
    while c >= b"0"[0]:
        x = 10*x+c-b"0"[0]
        c = getchar()
    if c == b"\r"[0]:
        getchar()
    return -x if sign else x

## IO ends
# reference https://codeforces.com/contest/1543/submission/121781191

def main():
    n,k = int(input()),int(input())
    _sum = []
    for i in range(2,n+1):
        stdout.write(f"or {1} {i}\n")
        stdout.flush()
        _or = int(input())
        if _or == -1:
            exit()
        stdout.write(f"and {1} {i}\n")
        stdout.flush()
        _and = int(input())
        if _and == -1:
            exit()
        _sum.append((_or&((1<<_or.bit_length())-1-_and))+2*_and)
    stdout.write(f"or {2} {3}\n")
    stdout.flush()
    _or = int(input())
    if _or == -1:
        exit()
    stdout.write(f"and {2} {3}\n")
    stdout.flush()
    _and = int(input())
    if _and == -1:
        exit()
    val = [(_sum[0]+_sum[1]-((_or&((1<<_or.bit_length())-1-_and))+2*_and))//2]
    for i in range(n-1):
        val.append(_sum[i]-val[0])
    rr = sorted(range(n),key=lambda xx:val[xx])
    stdout.write(f"finish {val[rr[k-1]]}\n")
    stdout.flush()

if __name__ == "__main__":
    main()