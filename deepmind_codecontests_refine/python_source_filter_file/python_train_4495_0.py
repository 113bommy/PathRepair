n=input()
d=[]
for i in n:
    if i.lower() not in ['a','e','i','o','u']:
        d.append(i.lower())

for j in d:
    print('.'+ str(j),end='')        
