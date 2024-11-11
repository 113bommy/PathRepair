#python3
import sys, threading, os.path
import collections, heapq, math,bisect
import string
from platform import python_version
import itertools
sys.setrecursionlimit(10**6)
threading.stack_size(2**27)     

def main():
    if os.path.exists('input.txt'):
        input = open('input.txt', 'r')
    else:
        input = sys.stdin
    #--------------------------------INPUT---------------------------------
    a,b,c = list(map(int, input.readline().split()))
    lis = sorted([a,b,c])
    sol = [0,0,0]
    imp = True
    if lis[0]>=lis[2]-lis[1]:
        sol[2] =lis[2]-lis[1]  
        lis[0]-=lis[2]-lis[1]
        lis[2]-=lis[2]-lis[1]
        if lis[0]%2==0 and lis[1]==lis[2]:
            imp = False
            sol[0]+=int(lis[0]/2)
            sol[2]+= int(lis[0]/2)

            sol[1]= (lis[2]-int(lis[0]/2))
    if imp:
        output = "Impossible"
    else:
        #print(sol)
        lassol = [0,0,0]
        if a == sol[0]+sol[2] and b == sol[0]+sol[1] and c == sol[1]+sol[2]:
            lassol = [sol[0],sol[1],sol[2]]
        elif a == sol[0]+sol[2] and c == sol[0]+sol[1] and b == sol[1]+sol[2]:
            lassol = [sol[2],sol[1],sol[0]]
        elif c == sol[0]+sol[2] and b == sol[0]+sol[1] and a == sol[1]+sol[2]:
            lassol = [sol[2],sol[1],sol[0]]
        elif c == sol[0]+sol[2] and a == sol[0]+sol[1] and b == sol[1]+sol[2]:
            lassol = [sol[1],sol[2],sol[0]]
        elif b == sol[0]+sol[2] and a == sol[0]+sol[1] and c == sol[1]+sol[2]:
            lassol = [sol[1],sol[0],sol[2]]
        elif b == sol[0]+sol[2] and c == sol[0]+sol[1] and a == sol[1]+sol[2]:
            lassol = [sol[1],sol[2],sol[0]]
        output = ' '.join(map(str, lassol))
    #-------------------------------OUTPUT----------------------------------
    if os.path.exists('output.txt'):
        open('output.txt', 'w').writelines(str(output))
    else:
        sys.stdout.write(str(output))


if __name__ == '__main__':
    main()
#threading.Thread(target=main).start()