from sys import stdin, stdout

get_string = lambda: stdin.readline().strip('\n')
get_intmap = lambda: map( int, get_string().split(' ') )
#get_intmap

def ncr_generator(n,r):
    ncrr = 1
    while True:
        yield ncrr
        n   += 1
        ncrr = ( ncrr * n // (n - r) ) 

def testcase():
    n = int(input())
    a = tuple(get_intmap()) 
    m = 998244353

    dp = [0]*(n + 1)# n good subsequence start at i = dp[i]
    dp[n] = 1 #consider empty as good seq
    for i in range(n-1,-1,-1):
        ai = a[i]
        if ai == 0: continue
        for j, ncrr in zip(range(i + ai + 1, n + 1),
                           ncr_generator(ai, ai)):
            dp[i] = ( dp[i] + ncrr * dp[j]) % m
    ans = 0
    for i in dp[:-1]:
        ans = (ans + i) % m
    print(ans)

testcase()
#for t in range(int(input())):
#    testcase()
