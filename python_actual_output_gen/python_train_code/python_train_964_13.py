import sys

n = int(sys.stdin.readline())
an = [int(x) for x in (sys.stdin.readline()).split()]

vmax = 0
vmin = 1001
for i in range(n - 2):
    vmax = 0
    
    v = an[i + 2] - an[i]
    if(v > vmax):
        vmax = v
    
    for j in range(i - 1):
        v = an[j + 1] - an[j]
        if(v > vmax):
            vmax = v
        
    for x in range(i + 2,  n - 1):
        v = an[x + 1] - an[x]
        if(v > vmax):
            vmax = v
                
    if(vmax < vmin):
        vmin = vmax
        
print(vmin)


