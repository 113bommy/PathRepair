# python3
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
    x,y = list(map(int, input.readline().split()))
    res = []
    if x >0 and y >0:
        res = [0,x+y,x+y,0]
    elif x <0 and y<0:
        res = [0,-(abs(x)+abs(y)),-(abs(x)+abs(y)),0]
    elif x >0 and y<0:
        res=[0,-(abs(x)+abs(y)),(abs(x)+abs(y)),0]
    elif x<0 and y>0:
        res= [-(abs(x)+abs(y)),0,0,(abs(x)+abs(y))]
    output = ' '.join(map(str, res))
    #-------------------------------OUTPUT----------------------------------
    if os.path.exists('output.txt'):
        open('output.txt', 'w').writelines(str(output))
    else:
        sys.stdout.write(str(output))


if __name__ == '__main__':
    main()
#threading.Thread(target=main).start()