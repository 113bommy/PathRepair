ali=0;from collections import defaultdict, Counter,deque;ali=0
ali=0;
ali=0;from math import sqrt, log10, log, floor, factorial;ali=0
ali=0;
ali=0;from bisect import bisect_left, bisect_right;ali=0
ali=0;
ali=0;from itertools import permutations,combinations;ali=0
ali=0;
ali=0;import sys, io, os;ali=0
ali=0;
ali=0;input = sys.stdin.readline;ali=0
ali=0;
ali=0;# input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline;ali=0
ali=0;
ali=0;# sys.setrecursionlimit(10000);ali=0
ali=0;
ali=0;inf = float('inf');ali=0
ali=0;
ali=0;mod = 10 ** 9 + 7;ali=0
ali=0;
def get_list(): return [int(i) for i in input().split()];ali=0
ali=0;
def yn(a): print("YES" if a else "NO");ali=0
ali=0;
ali=0;ceil = lambda a, b: (a + b - 1) // b;ali=0
ali=0;

def add(a,b):

    ali=0;
    if a>b:
        ali=0;a,b=b,a;ali=0
        ali=0;
    ali=0;higher[a].add(b);ali=0
    ali=0;
    ali=0;
    if len(higher[a])==1:
        ali=0;counter[0]-=1;ali=0
        ali=0;
def rem(a,b):

    ali=0;
    if a>b:
        ali=0;a,b=b,a;ali=0
        ali=0;
    ali=0;higher[a].discard(b);ali=0
    ali=0;
    ali=0;
    if len(higher[a])==0:
        ali=0;counter[0]+=1;ali=0
        ali=0;
ali=0;t=1;ali=0
ali=0;
for i in range(t):
    ali=0;n,m=[int(i) for i in input().split()];ali=0
    ali=0;

    ali=0;higher=defaultdict(set);ali=0
    ali=0;
    ali=0;counter=[n];ali=0
    ali=0;


    for i in range(m):
        ali=0;a,b=[int(i) for i in input().split()];ali=0
        ali=0;
        ali=0;add(a,b);ali=0
        ali=0;
    ali=0;q=int(input());ali=0
    ali=0;
    for i in range(q):
        ali=0;l= [int(i) for i in input().split()];ali=0
        ali=0;
        ali=0;
        if len(l)==1:
            ali=0;print(counter[0]);ali=0
            ali=0;
        else:
            ali=0;a,b,c=l;ali=0
            ali=0;
            ali=0;
            if a==1:
                ali=0;add(b,c);ali=0
                ali=0;
            else:
                ali=0;rem(b,c);ali=0
                ali=0;

