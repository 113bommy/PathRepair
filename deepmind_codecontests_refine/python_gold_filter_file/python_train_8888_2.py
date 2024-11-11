def spliter():
    d = input()
    a = d.split()
    r = []
    for i in a:
        k = int(i)
        r.append(k)
    return r


n = spliter()
lst1=[]
lst2=[]
count=[]
for i in range(n[0]):
    a=spliter()
    lst1.append(a[1])
    lst2.append(a[0])
for i in range(n[0]):
    for j in range(n[0]):
        if i != j:
            if lst1[i] == lst2[j]:
                count.append(lst2[j])
                lst2[j]=0
print(len(lst2)-len(count))