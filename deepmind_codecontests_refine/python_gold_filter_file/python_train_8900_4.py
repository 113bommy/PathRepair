from collections import Counter
def mp():  return map(int,input().split())
def lt():  return list(map(int,input().split()))
def pt(x):  print(x)
def ip():  return input()
def it():  return int(input())
def sl(x):  return [t for t in x]
def spl(x): return x.split()
def aj(liste, item): liste.append(item)
def bin(x):  return "{0:b}".format(x)
def listring(l): return ' '.join([str(x) for x in l])
def printlist(l): print(' '.join([str(x) for x in l]))

n = it()
prefix = 0
result = 0
a = lt()
for x,y in zip(a,sorted(a)):
    prefix += (x-y)
    if prefix == 0:
        result += 1
print(result)
    
    
    