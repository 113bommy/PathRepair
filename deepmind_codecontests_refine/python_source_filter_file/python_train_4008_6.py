n,w=[int(x) for x in input().split()]
caps=[int(x) for x in input().split()]
caps.sort()
g=caps[0]
b=caps[n]
if(b<2*g):
    g=b/2
print(g*3*n)
