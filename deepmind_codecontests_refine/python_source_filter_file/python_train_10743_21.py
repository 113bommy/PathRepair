from sys import stdin, stdout, setrecursionlimit
import threading

# tail-recursion optimization
# In case of tail-recusion optimized code, have to use python compiler.
# Otherwise, memory limit may exceed.
# declare the class class Tail_Recursion_Optimization
class Tail_Recursion_Optimization:
    def __init__(self, recursion_limit, stack_size):
        setrecursionlimit(recursion_limit)
        threading.stack_size(stack_size)
        return None
        
class SOLVE:
    def solve(self):
        R = stdin.readline
        f = open('input.txt');R = f.readline
        W = stdout.write
        
        ans = []
        
        for i in range(int(R())):
            n, m = [int(x) for x in R().split()]
            a    = [int(x) for x in R().split()]
            
            if m < n or n == 2:
                ans.append('-1')
            else:
                ans.append(str(2*sum(a)))
                for i in range(1, n):
                    ans.append(str(i) + ' ' + str(i+1))
                ans.append(str(n) + ' ' + '1')
        
        W('\n'.join(ans))
        return 0
        
def main():
    s = SOLVE()
    s.solve()
#Tail_Recursion_Optimization(10**7, 2**26)
threading.Thread(target=main).start()