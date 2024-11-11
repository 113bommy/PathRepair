import sys
stdin = sys.stdin

sys.setrecursionlimit(10**5)

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

n = ni()
s = " " + ns()
q = ni()
k = list(li())

def find_ans(k:int):
    cnt = [0,0,0]
    ans = 0
    
    for i in range(1, n+1):
        
        if s[i] == 'C':
            ans += cnt[2]

        if i-k+1 > 0:
            if s[i-k+1] == 'D':
                cnt[0] -= 1
                cnt[2] -= cnt[1]
                
            elif s[i-k+1] == 'M':
                cnt[1] -= 1
                
        if s[i] == 'D':
            cnt[0] += 1    
        
        elif s[i] == 'M':
            cnt[2] += cnt[0]
            cnt[1] += 1

            
    return ans
        
for ki in k:
    print(find_ans(ki))