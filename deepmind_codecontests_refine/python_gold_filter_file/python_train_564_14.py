# cook your dish here
a = input()
b = input()
dica = {}
dicb = {}
for i in range(len(a)):
    if(a[i] not in dica):
        dica[a[i]] = 1
    else:
        dica[a[i]]+=1

for i in range(len(b)):
    if(b[i] not in dicb):
        dicb[b[i]] = 1
    else:
        dicb[b[i]]+=1

flag =1
p = len(b)
for i in dicb:
    if((i not in dica) or (dica[i]<dicb[i])):
        flag = 0
        break
if(flag and len(a)==len(b)):
    flag = -1
    print("array")
    
elif(flag):
    q = 0
    for i in range(len(a)):
        if(a[i]==b[q]):
            q+=1
        if(q==p):
            print("automaton")
            flag = -1
            break
if(flag==1):
    print("both")

if(flag == 0):
    print("need tree")