# -*- coding: utf-8 -*-
#import pdb;    pdb.set_trace()
import sys

def solv(v):
    w = set(v)
    if len(w)==1 or len(w)==3:
        d={1:2, 2:2, 3:2}
    elif 1 in w and 2 in w:
        d={1:1, 2:2}
    elif 2 in w and 3 in w:
        d={2:1, 3:2}
    else:
        d={3:1, 1:2}
    return(list(map(lambda x:d[x], v) ))
def main():
    if True:
        fh = sys.stdin
    else:
        fh = open('vol2_0205.txt', 'r')
    try:
        while True:
            te = []
            for _ in range(5):
                x=int(fh.readline().strip())
                if x==0:
                    raise Exception
                te.append(x)
            b=(solv(te))
            for i in b:
                print(i)
    except Exception:
        1
    fh.close()
    
if __name__ == '__main__':
    main()

