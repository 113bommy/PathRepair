n=int(input())
a=[int(i)//400 for i in input().split()]

b=[]
c=0
for i in a:
    if i<8:
        b.append(i)
    else:
        c+=1
b=set(b)

print(len(b),len(b)+c)