#!/usr/bin/env python3
import atexit
import io
import sys
import bisect

_I_B = sys.stdin.read().splitlines()
input = iter(_I_B).__next__
_O_B = io.StringIO()
sys.stdout = _O_B

@atexit.register
def write():
    sys.__stdout__.write(_O_B.getvalue())


def main():
    n=int(input())
    b=list(map(int,input().split()))
    bd=dict()
    for i in b:
        try:
            bd[i]+=1
        except KeyError:
            bd[i]=1
    co=0
    md=max(b)-min(b)
    if md==0:
        for i in bd:
            co+=(bd[i]*(bd[i]-1))
    else:
        for i in bd:
            try:
                co+=(bd[i]*bd[i+md])
            except KeyError:
                co+=0
            
    print(md,co)



if __name__=='__main__':
    main()