"""
NTC here
"""
import sys
inp= sys.stdin.readline
input = lambda : inp().strip()
flush= sys.stdout.flush
# import threading
# setrecursionlimit(10**6)
# threading.stack_size(2**26)

def iin(): return int(input())
def lin(): return list(map(int, input().split()))

# range = xrange
# input = raw_input

def main():
    n, m, k= lin()
    if k>4*n*m-2*n-2*m:
        print('NO')
    else:
        a = []
        for i in range(n-1):
            #print('Left', k)
            if k == 0:break
            if k<=4*(m-1) and m-1:
                if k<=3*(m-1):
                    x = k//3
                    x1 = k%3
                    a.append([x, 'RDU'])
                    if x1:a.append([1, 'RDU'[:x1]])
                    
                else:
                    a.append([m-1, 'RDU'])
                    k-=3*(m-1)
                    a.append([k, 'L'])
                k=0
            else:
                if m-1:
                    a.append([m-1, 'RDU'])
                    a.append([m-1, 'L'])
                a.append([1, 'D'])
                k = k-4*(m-1)-1
        else:
            if k and m-1:
                if k<2*m-2:
                    if k<=m-1:
                        a.append([k,'R'])
                        
                    else:
                        k-=m-1
                        a.append([m-1,'R'])
                        a.append([k, 'L'])
                    k=0
                else:
                    a.append([m-1,'R'])
                    a.append([m-1, 'L'])
                        
                    k -= 2*m-2
        if k:
            a.append([k, 'U'])
        print('YES')
        print(len(a))
        for i,j in a:
            print(i,j)







             



















        
main()
#threading.Thread(target=main).start()