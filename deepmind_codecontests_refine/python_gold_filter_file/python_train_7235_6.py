def mp():  return map(int,input().split())
def lt():  return list(map(int,input().split()))
def pt(x):  print(x)
def ip():  return input()
def it():  return int(input())
def sl(x):  return [t for t in x]
def spl(x): return x.split()
def aj(liste, item): liste.append(item)
def bin(x):  return "{0:b}".format(x)

n = it()
a = lt()
result = abs(a[0])
for i in range(len(a)-1):
    result += abs(a[i]-a[i+1])
print(result)

    
    


    
    