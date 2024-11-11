import sys
import math
def fn(l,d,v,g,r):
    t = float(d)/float(v)
    if t<g:
        return float(l)/float(v)
    elif t<=g+r:
        t = g+r
        return t+ (float(l)-float(d))/float(v)
    elif t>g+r:
        t1=t
        k = t//(g+r)
        t = t- k*(g+r)
        if t<g:
            return float(l)/float(v)
        elif t<=g+r:
            t = t1
            return t+ (float(l)-float(d))/float(v)
if __name__ == '__main__':    
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    l = (data[0])
    d = data[1]
    v = data[2]
    g = data[3]
    r = data[4]
    print(fn(l,d,v,g,r))