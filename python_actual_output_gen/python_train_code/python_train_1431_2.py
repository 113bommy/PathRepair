n=int(input())
a=[int (a) for a in input().split()]
a=a[::-1]
d=[]
for i in a:
    if i not in d:
        d.append(i)
        

print (len(d))
for i in d:
    print (i, end=' ')