
n,m = map(int,input().split())
l = [int(x) for x in input().split()]

c = []
remaining = m
for i in range(n):

    if l[i] < remaining:
        c.append(0)
        remaining -= l[i]
    elif l[i] == remaining:
        c.append(1)
        remaining = m
    elif l[i] > remaining:
        foo = l[i] - remaining
        
        c.append(1 + foo//m)
        remaining = m - foo%m  
    print("-->",remaining)          
        

print(*c)   