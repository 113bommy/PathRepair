a=['purple','green','blue','orange','red','yellow']
b=set()
for _ in range(int(input())):
    b.add(input())
c=(set(a)).difference(b)
print(len(c))
dic=[]
for i in c:
    if(i==a[0]):
        dic.append('Power')
    elif (i == a[1]):
        dic.append('Time')
    elif (i == a[2]):
        dic.append('Space')
    elif (i == a[3]):
        dic.append('Soul')
    elif (i == a[4]):
        dic.append('Reality')
    elif (i == a[5]):
        dic.append('Mind')
print('\n'.join(dic),end="")
