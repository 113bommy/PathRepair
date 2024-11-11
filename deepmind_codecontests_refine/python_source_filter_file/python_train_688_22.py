n=[0]*1000
b=int(input())
o=''
res=1
i=2
n[0]=1
n[1]=1
while i<b:
    res=n[i-1]+n[i-2]
    n[i]=res
    i+=1
for y in range(1, b+1):
    if y in n:
        o+='O'
    else:
        o+='o'
print(str(o))        
