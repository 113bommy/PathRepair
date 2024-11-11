import sys
import collections

infile = sys.stdin.buffer
def gs()  : return infile.readline().rstrip()
def gi()  : return int(gs())
def gss() : return gs().split()
def gis() : return [int(x) for x in gss()]

MOD = (10 ** 9) + 7
INF = 10 ** 10

p = [1 for i in range(2*(10 ** 5) + 2)]
for i in range(1,len(p)):
    p[i] = p[i-1] * 2
    p[i] %= MOD

def pow(a,n):
    return p[n]
    if n == 0: return 1
    t = pow(a,n//2)
    ans = (t * t) % MOD 
    return ans * (a if n &1 else 1) % MOD

def compute(n):
    if n & 1:
        return pow(2, n-1)
    return pow(2, n-1) -1



def dfs(i, k, n,s,mem):
    if i == k:
        return 1
    prev = 1
    p = pow(2,n)
    c = 1
    for i in range(k-1,-1,-1):
        cur = 0
        cur = c if n & 1 == 0 else prev
        c*= p
        c %= MOD    
        cur += (s * prev) %MOD
        cur %= MOD
        prev = cur
    return cur


def f(n,k):
    return dfs(0 , k, n,compute(n),[])

def main(infn="") :
    global infile
    infile = open(infn,"r") if infn else open(sys.argv[1],"r") if len(sys.argv) > 1 else sys.stdin
    
    ######################################################################
    cn = int(input())
    for u in range(cn):
        n,k = map(int, input().split())
        print (f(n,k))
    ######################################################################

if __name__ == '__main__' :
    main()
    #sys.stdout.flush()