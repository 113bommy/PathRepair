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
            a = [0] + [int(x) for x in R().split()]
            
            tmp_max_gap = {}
            for j in range(1, n+1):
                if a[j] not in tmp_max_gap:
                    tmp_max_gap[a[j]] = [j, j] 
                else:
                    tmp_max_gap[a[j]][0] = max(tmp_max_gap[a[j]][0], j-tmp_max_gap[a[j]][1])
                    tmp_max_gap[a[j]][1] = j
            #print(tmp_max_gap)
                    
            max_gap = []
            for j in tmp_max_gap:
                max_gap.append((j, max(tmp_max_gap[j][0], n+1-tmp_max_gap[j][1])))
            
            max_gap.sort(key = lambda x : x[0])
            #print(max_gap)
            
            color = ['-1' for j in range(n+1)]
            pos   = n+1
            for j in range(len(max_gap)):
                if max_gap[j][1] < pos and color[j] == '-1':
                    color[max_gap[j][1]] = str(max_gap[j][0])
                    pos = max_gap[j][1]
            #print(color)
                    
            val = '-1'
            for j in range(1, n+1):
                if color[j] != val and color[j] != '-1':
                    val = color[j]
                color[j] = str(val)
            
            ans.append(' '.join(color[1:]))
        
        W('\n'.join(ans))
        return 0
        
def main():
    s = SOLVE()
    s.solve()
#Tail_Recursion_Optimization(10**7, 100*1024**2) # recursion-call size, stack-size in byte (MB*1024**2)
#threading.Thread(target=main).start()
main()