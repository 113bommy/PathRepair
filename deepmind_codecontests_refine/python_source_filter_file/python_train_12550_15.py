def answer():
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    c = []
    i=0
    while i<len(b)-1:
        diff = -b[i]+b[i+1]
        c.append((diff))
        i+=1
    sub=0
    i=len(c)-1
    j=0
    #print(c)
    while i>=0:
        j+=1
        if c[i]>=a[1]:
            return j
        i-=1
    return len(c)
print(answer())