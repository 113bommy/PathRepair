import sys
from itertools import permutations
#a=list(map(int,input().strip().split(' ')))
#n,k,s= map(int, sys.stdin.readline().split(' '))
def vow(s):
    k=['a','e','i','o','u']
    l=len(s)
    i=0
    while(i<(len(s)-1)):
        if((s[i] in k) and (s[i+1] in k)):
            s=s[:i+1] + s[(i+2):]
            i-=1
        i+=1
    print(s)   
    
n=int(input())
s=str(input())
vow(s)
