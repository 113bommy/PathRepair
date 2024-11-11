n=input()
from math import ceil
stroka=ceil(len(n)/20)
if len(n)%stroka> 0:
    stolb=(len(n)//stroka)+1
    zvezda=stroka-len(n)%stroka
else:
    stolb=(len(n)//stroka)
    zvezda=0
p=0
for i in range(zvezda):
    n=n[0:i*stolb]+'*'+n[i*stolb:]
print(n)    
print(stroka,stolb)
for i in range(stroka):
    for j in range(stolb):
        print(n[j+p],end='')
    p+=stolb
    print()    
    
