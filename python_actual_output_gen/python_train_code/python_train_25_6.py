n=int(input())
ar = list(map(int, input().strip().split(' ')))

lst1=list(filter(lambda x: (x<=500000) , ar))
lst2=list(filter(lambda x: (x>500000) , ar))
lst1.append(1)
lst2.append(1000000)
m=0

for i in range(len(lst1)):
    if lst1[i]>m:
        m=lst1[i]
mi=min(lst2)
mi=1000000-mi

if mi>m:
    print(mi)
else:
    print(m)
    