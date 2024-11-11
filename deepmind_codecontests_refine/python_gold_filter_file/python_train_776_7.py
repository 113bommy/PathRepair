a = list(map(int,list(input())))
x = []
g = max(a)
for _ in range(g):
    c=''
    for i in range(len(a)):
        if a[i]>0:
            a[i]-=1
            c = c+'1'
        elif c:
            c = c+'0'
    x+=[c]
print(g)
print(*sorted(x))
