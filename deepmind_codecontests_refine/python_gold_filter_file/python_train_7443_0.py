from collections import Counter
from fractions import gcd
def mp():  return map(int,input().split())
def lt():  return list(map(int,input().split()))
def pt(x):  print(x)
def ip():  return input()
def it():  return int(input())
def sl(x):  return [t for t in x]
def spl(x): return x.split()
def aj(liste, item): liste.append(item)
def bin(x):  return "{0:b}".format(x)
def printlist(l): print(' '.join([str(x) for x in l]))
def listring(l): return ''.join([str(x) for x in l])

n = it()
a = lt()
L = []
a.sort(reverse = True)
c = Counter(a)
for r in a:
    while c[r] > 0 and n > 0:
        c[r] -= 1
        for j in L:
            c[gcd(j,r)] -= 2
        L.append(r)
        n -= 1
    if n == 0:
        break
printlist(L)

    
    


