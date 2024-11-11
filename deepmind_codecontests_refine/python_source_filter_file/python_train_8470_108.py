from collections import OrderedDict
x=int(input())
for i in range(x+1,9000):
    x=str(i)
    y=''.join(set(x))
    if(len(x)==len(y)):
        print(i)
        break