x=int(input())
l=[]
for b in range (2,32):
    for i in range (1,10):
        if b**i <=x:
            l.append (b**i)
print(max(l))