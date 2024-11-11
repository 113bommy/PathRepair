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
    mod = 10**9 + 7
        
    def twon(self, n):
        if n == 0:
            return 1
        
        x = self.twon(n//2)
        if n%2:
            return (2*x**2) % self.mod
        else:
            return (x**2) % self.mod
    
    def solve(self):
        R = stdin.readline
        f = open('input.txt');R = f.readline
        W = stdout.write
        
        n = int(R())
        
        fact_n = 1
        for i in range(2, n+1):
            fact_n *= i
            fact_n %= self.mod
        
        two_n  = self.twon(n-1)
        
        W('%d\n' % (fact_n-two_n + self.mod*(fact_n<two_n)))
        
        return 0
        
def main():
    s = SOLVE()
    s.solve()
#Tail_Recursion_Optimization(10**7, 2**18)
threading.Thread(target=main).start()