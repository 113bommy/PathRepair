mx=[]
a=input()
jump=0
for i in range(len(a)):
    if a[i] in ['A','E','I','O','U','Y']:
        mx.append(jump+1)
        jump=1
    else:
        jump+=1
mx.append(jump)

print(max(mx)-1)
