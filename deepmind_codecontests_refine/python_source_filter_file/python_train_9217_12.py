from sys import stdin, stdout, setrecursionlimit
import threading

# tail-recursion optimization
# In case of tail-recusion optimized code, have to use python compiler.
# Otherwise, memory limit may exceed.
# declare the class Tail_Recursion_Optimization
class Tail_Recursion_Optimization:
    def __init__(self, RECURSION_LIMIT, STACK_SIZE):
        setrecursionlimit(RECURSION_LIMIT)
        threading.stack_size(STACK_SIZE)
        return None
        
class SOLVE:
    n = a = dp = None

    def DP(self, pos, gym, contest):
        if pos == self.n:
            return 0
        
        if self.dp[pos][gym][contest] != None:
            return self.dp[pos][pos][contest]
        
        
        if self.a[pos] == 0:
            self.dp[pos][gym][contest] = 1 + self.DP(pos+1, 0, 0)
        
        elif self.a[pos] == 1:
            if contest == 1:
                self.dp[pos][gym][contest] = 1 + self.DP(pos+1, 0, 0)
            else:
                self.dp[pos][gym][contest] = self.DP(pos+1, 0, 1)
        
        elif self.a[pos] == 2:
            if gym == 1:
                self.dp[pos][gym][contest] = 1 + self.DP(pos+1, 0, 0)
            else:
                self.dp[pos][gym][contest] = self.DP(pos+1, 1, 0)
        
        else:
            if gym == contest == 0:
                total1 = total2 = None
                total1 = self.DP(pos+1, 1, 0)
                total2 = self.DP(pos+1, 0, 1)
                dp[pos][gym][contest] = min(total1, total2)
            elif gym == 0:
                self.dp[pos][gym][contest] = self.DP(pos+1, 1, 0)
            else:
                self.dp[pos][gym][contest] = self.DP(pos+1, 0, 1)
            
        return self.dp[pos][gym][contest]
    
    def solve(self):
        R = stdin.readline
        #f = open('input.txt');R = f.readline
        W = stdout.write
        
        self.n  = int(R())
        self.a  = [int(x) for x in R().split()]
        self.dp = [[[None, None], [None, None]] for i in range(self.n)]
        
        W('%d\n' % self.DP(0, 0, 0))
        return 0
        
def main():
    s = SOLVE()
    s.solve()
Tail_Recursion_Optimization(10**7, 100*1024**2) # recursion-call size, stack-size in byte (MB*1024**2)
threading.Thread(target=main).start()
#main()