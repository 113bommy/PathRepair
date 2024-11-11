#!/usr/bin/env python3
 
from __future__ import division, print_function

def main():
    import sys
    data = iter(sys.stdin.buffer.read().decode('ascii').split())
    n = int(next(data))
    res = [None] * n
    for i in range(n):
        digits = {i:0 for i in range(10)}
        s = next(data)
        for c in s:
            digits[int(c)] += 1
        s = sorted(s)
        if s == "0" or s == "00" or s == "06":
            res[i] = "red"
        elif len(s) <= 2 or digits[0] == 0:
            res[i] = "cyan"
        else:
            tot = sum(k * v for k, v in digits.items()) % 3
            digits[0] -= 1
            p = sum(digits[2 * j] for j in range(5))
            if tot == 0 and p > 0:
                res[i] = "red"
            else:
                res[i] = "cyan"
    sys.stdout.buffer.write('\n'.join(str(x) for x in res).encode('ascii'))    
    return 0
 
if __name__ == '__main__':
    main()
