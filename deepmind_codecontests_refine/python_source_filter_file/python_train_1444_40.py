import sys
import math

def divlist(n):
   sl=[]
   ll=[]
   for x in range(1,int(math.sqrt(n))+1):
       if n%x==0:
           sl.append(x)
           ll.append(n//x)
   ll.reverse()
   sl.extend(ll)
   return sl

def f(b,n):
    if n<b:
        return n
    else:
        return f(b,n//b)+(n%b)

def main(n,s):
    if n<s:
        return print(-1)
    elif n==s:
        return prnit(n+1)
    else:
        dl=divlist(n-s)
        for x in dl:
            if s==f(x+1,n):
                return print(x+1)
        return print(-1)

n=int(sys.stdin.readline().strip())
s=int(sys.stdin.readline().strip())

main(n,s)
