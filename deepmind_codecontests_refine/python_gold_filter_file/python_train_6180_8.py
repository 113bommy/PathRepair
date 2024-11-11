f=input()
f=f.split(" ")
buy=0
countt=0
while countt<4:
    g=f.count(f[0])
    countt+=g
    c=f[0]
    if g>1:
        buy+=g-1
    for i in range(0,g):
        f.remove(c)
print(buy)
