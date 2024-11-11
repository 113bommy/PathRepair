wires=list(input())
#print(len(wires))
mp='+-'
pm='-+'
h=0
b=0
if (len(wires)%2)!=0:
    #print(len(wires))
    print("No")
    exit()
for i in range(0,len(wires),2):
    l=wires[i]+wires[i+1]
    if l==mp:
        h+=1
    else:
        b+=1
if h==b:
    print('Yes')
else:
    print('No')




















''' while len(wires)!=0 and i<len(wires)-1:
        if i<0:
            i=0
        #print(wires,i)
        if wires[i]==wires[i+1]:
            wires.pop(i+1)
            wires.pop(i)
            i=i-1
        else:
            i+=1
if len(wires)==0:
    print("Yes")
else:
    print('No')
    '''
