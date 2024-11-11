"""
NTC here
"""
from sys import stdin, setrecursionlimit
setrecursionlimit(10**7)

def iin(): return int(stdin.readline())
 
 
def lin(): return list(map(int, stdin.readline().split()))

# range = xrange
# input = raw_input
dp=[-1]*(10**5+10)
def check(n, idx, a):
    # a is array
    global dp
    if dp[idx]!=-1:
        return dp[idx]
    step = a[idx]
    ans=0
    odd=0
    for i in range(idx+step, n, step):
        if a[i]>a[idx]:
            x=check(n, i, a)+1
            if x%2:odd=x
            ans=max(x, ans)
    for i in range(idx-step, -1, -step):
        if a[i]>a[idx]:
            x=check(n, i, a)+1
            if x%2:odd=x
            ans=max(x, ans)
    dp[idx]=ans if odd==0 else odd
    return dp[idx]



def main():
    
    n=iin()
    a=lin()
    for i in range(n):
        check(n, i, a)
    ans=[]
    #print(dp[:n])
    for i in range(n):
        ans.append(['B','A'][dp[i]%2])
    print(''.join(ans))





main()