#python3
import sys, threading, os.path
import collections, heapq, math,bisect
import string
from platform import python_version
import itertools
sys.setrecursionlimit(10**6)
threading.stack_size(2**27)     

def scompute(x):
    str1 = str(x)
    sum = 0
    for c in str1:
        sum+=int(c)
    return sum

def main():
    if os.path.exists('input.txt'):
        input = open('input.txt', 'r')
    else:
        input = sys.stdin
    #--------------------------------INPUT---------------------------------
    a, b, c = list(map(int, input.readline().split()))
    lis = []
    for i in range(1,100000):
        lis.append((i,(b*pow(i,a))+c))
    sol = []
    for x,y in lis:
        if y>0 and y < 10e9 and scompute(y)==x:
            sol.append(y)
    #print(lis)
    if len(lis)==0:
        output = 0
    else:
        output = str(len(sol))
        output += '\n'
        output += ' '.join(map(str, sol))
    #-------------------------------OUTPUT----------------------------------
    if os.path.exists('output.txt'):
        open('output.txt', 'w').writelines(str(output))
    else:
        sys.stdout.write(str(output))


if __name__ == '__main__':
    main()
#threading.Thread(target=main).start()