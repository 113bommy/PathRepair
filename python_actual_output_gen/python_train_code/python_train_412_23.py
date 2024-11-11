a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())
if (f>e):
    suit2 = min([b,c,d])
    d = d - suit2
    suit1 = min([a,d])
    
else:
    suit1 = min([a-d])
    d = d - suit1
    suit2 = min([b,c,d])
print(suit2*f+suit1*e)