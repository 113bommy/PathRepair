x,y,z,t= [int(i) for i in input().split()]
bigst=max(x,y,z,t)
lst=[x,y,z,t]
for i in range(len(lst)):
    if i==bigst:
        lst.pop(i)
        break
print(f"{bigst-lst[0]} {bigst-lst[1]} {bigst-lst[2]}")