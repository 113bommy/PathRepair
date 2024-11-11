n=int(input())
print(6-n)
s={"Time","Mind","Soul","Power","Reality","Space"}
l=[]
for i in range(n):
    a=input()
    if a=="red":
        l.append("Reality")
    elif a=="purple":
        l.append("Power")
    elif a=="green":
        l.append("Time")
    elif a=="orange":
        l.append("Soul")
    elif a=="yellow":
        l.append("Mind")
    else:
        l.append("Space")
k=s-set(l)
print(*k,sep="\n")