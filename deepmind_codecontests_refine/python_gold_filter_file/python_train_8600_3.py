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
    def solve(self):
        R = stdin.readline
        #f = open('input.txt');R = f.readline
        W = stdout.write
        
        ans = []
        
        for i in range(int(R())):
            n = int(R())
            if n in [1, 2, 3, 5, 7, 11]:
                ans.append('-1')
            else:
                if not n%2:
                    if not n%4:
                        ans.append(str(n//4))
                    else:
                        ans.append(str(1 + (n-6)//4))
                else:
                    n -= 9
                    if not n%4:
                        ans.append(str(1 + n//4))
                    else:
                        ans.append(str(2+(n-6)//4))
        
        W('\n'.join(ans))
        return 0
        
def main():
    s = SOLVE()
    s.solve()
#Tail_Recursion_Optimization(10**7, 2**26) # recursion-call size, stack-size in byte
threading.Thread(target=main).start()