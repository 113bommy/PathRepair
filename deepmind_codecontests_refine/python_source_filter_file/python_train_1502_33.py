import sys;import copy;
import math;
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
 
#t = int(input());
t=1;
for test in range(t):
    S = input();
    b = S.count("B");
    s = S.count("S");
    c = S.count("C");
    nb,ns,nc = get_ints();
    pb,ps,pc = get_ints();
    r = int(input());
    def good(x):
        #print(x);
        price = (x*b-min(x*b,nb))*pb + (x*s-min(x*s,ns))*ps + (x*c-min(x*c,nc))*pc;
        
        if(price<=r):
            return True;
        else:
            return False;
    l = 0;
    h = 10**12;
    while(l<h):
        mid = (l+h)//2 + 1;
        if(good(mid)):
            l=mid;
        else:
            h=mid-1;
    print(l);
