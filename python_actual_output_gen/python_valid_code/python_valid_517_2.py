"""
    Author : Ashish Sasmal
    Python3 / PyPy3
"""

from sys import stdin as sin
def aint():return int(input())
def amap():return map(int,sin.readline().split())
def alist():return list(map(int,sin.readline().split()))
def astr():return input()

for _ in range(aint()):
    s = input()
    t = input()
    if len(s)>=len(t):
        j =  len(s)-1
        c=0
        i = len(t)-1
        while i>=0:
            if j>=0:
                if s[j]!=t[i]:
                    j-=2
                    i+=1
                else:
                    c+=1
                    j-=1
            else:
                break
            i-=1
        
        if j>=0 and c==len(t):
            print("YES")
        else:
            print("NO")
        
    else:
        print("NO")