import sys
import collections

infile = sys.stdin.buffer
def gs()  : return infile.readline().rstrip()
def gi()  : return int(gs())
def gss() : return gs().split()
def gis() : return [int(x) for x in gss()]

MOD = 10 ** 9 
MOD += 7
INF = 10 ** 10


pw =[1 for i in range(2*(10**5)+3)]
for i in range(1, len(pw)):
    pw[i] *= pw[i-1]
    pw[i] *= 2
    pw[i] %= MOD

fact =[i for i in range(2*(10**5)+3)]
fact[0] = 1
for i in range(2, len(fact)):
    fact[i] *= fact[i-1]
    fact[i] %= MOD
factinv = [1 for _ in range(len(fact))]
factinv[len(fact)-1] = pow(fact[len(fact)-1], MOD-2,MOD) 
for ii in range(len(fact)-2,-1,-1):
    factinv[ii] = factinv[ii+1] * (ii+1)
    factinv[ii] %= MOD

def nCr(n,r):
    return (fact[n] * factinv[r] * factinv[n-r]) % MOD

def compute(n):
    s = 0
    for t in range(0, n, 2):
        s += nCr(n,t)
        s %=MOD
    return s


def dfs(i, k, n,s,mem):
    if k==0:
        return 1
    prev= 1
    p = pw[n]
    c = 1
    for i in range(k):
        ans = 0

        # every one is a 1 
        if n & 1 == 0:
            ans += pow(p, i,MOD)
            c *= p
            c %= MOD
            ans %= MOD
        else:
            ans += prev
            ans %= MOD

        # not every one is a 1 
        ans += s * prev
        ans %= MOD
        prev = ans

    return ans


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
