"""
NTC here
"""
import sys
input= sys.stdin.readline
# import threading
# setrecursionlimit(10**6)
# threading.stack_size(2**26)

def iin(): return int(input())
def lin(): return list(map(int, input().split()))

# range = xrange
# input = raw_input

def main():
    t=iin()
    while t:
        t-=1
        n = iin()
        a = lin()
        for i in range(n-1):
            if abs(a[i+1]-a[i])>=2:
                print('YES')
                print(i, i+1)
                break
        else:
            print('NO')


        

        



                









        
main()
#threading.Thread(target=main).start()
