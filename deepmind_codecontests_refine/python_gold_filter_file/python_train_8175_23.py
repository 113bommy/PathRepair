import sys,os,io
from sys import stdin
from functools import cmp_to_key
from bisect import bisect_left , bisect_right
from collections import defaultdict
def ii():
    return int(input())
def li():
    return list(map(int,input().split()))
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r") ; sys.stdout = open("output.txt","w") 
# else:
#     input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

for _ in range(1):
    s = input()
    n = len(s)
    d =defaultdict(lambda:0)
    d['b']='d'
    d['d']='b'
    # d['i']='i'
    d['o']='o'
    d['p']='q'
    d['q']='p'
    d['v']='v'
    d['w']='w'
    d['x']='x'
    d['A']='A'
    d['H']='H'
    d['I']='I'
    d['M']='M'
    d['O']='O'
    d['T']='T'
    d['U']='U'
    d['V']='V'
    d['W']='W'
    d['X']='X'
    d['Y']='Y'
    if n%2==1:
        j=i = n//2
        if d[s[i]]==s[i]:
            i=i-1
            j+=1
            while(i>=0):
                if d[s[i]]==s[j]:
                    i-=1
                    j+=1
                else:
                    print("NIE")
                    exit(0)
            print("TAK")
        else:
            print("NIE")
            exit(0)
    else:
        j=i = n//2
        i=i-1
        # j+=1
        while(i>=0):
            # print(i,j)
            # print(s[i],s[j])
            # print(d[s[i]],s[j])
            if d[s[i]]==s[j]:
                i-=1
                j+=1
            else:
                print("NIE")
                exit(0)
        print("TAK")


