import sys;
import math;
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()

t = int(input());
for test in range(t):
    n,k = get_ints();
    ans=0;
    if(n<=k):
        ans = n*(n-1)//2;
        ans+=1;
    else:
        ans += k*(k+1)//2;
    print(ans);
