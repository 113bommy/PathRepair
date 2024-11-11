s=int(input())
l=[]
while (s not in l):
    l.append(s)
    if s%2==0:
        s//=2
    else:
        s=3*s+1
print(l)
print(len(l)+1)