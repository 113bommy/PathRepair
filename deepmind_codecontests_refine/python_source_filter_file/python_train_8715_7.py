x = int(input())

dict= {'purple': 'Power', 'green':'Time', 'blue': 'Space','yellow':'Mind','red':'Reality','orange':'Soul'}
ncol = []
for i in range (0,6-x):
    z = input()
    ncol.append(z)
for i in range(0,len(ncol)):
    if ncol[i] == 'purple':
        del dict['purple']
    elif ncol[i] == 'green':
        del dict['green']
    elif ncol[i] == 'blue':
        del dict['blue']
    elif ncol[i] == 'yellow':
        del dict['yellow']
    elif ncol[i]== 'red':
        del dict['red']
    elif ncol[i] == 'orange':
        del dict['orange']
print(6-x)
for key in dict:
    print(dict[key])
    
    
    