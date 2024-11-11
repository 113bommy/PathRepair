m=[]
for i in range(5):
    m.append(input().split())
for i  in range(5):
    if m[i].count('1')==1:
        r=i
        c=m[i].index('1')
x=abs(2-r)+abs(2-c)
print(x)