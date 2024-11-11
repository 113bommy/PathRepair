x=int(input())
l=[]
for b in range (1,32):
    for i in range (2,10):
        if b**i <=x:
            l.append (b**i)
print(max(l))