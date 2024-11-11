def inplst():
    return list(map(int,input().split()))
n=int(input())
l=inplst()
l.sort()
r=0
ones=l.count(1)
twos=l.count(2)
threes=l.count(3)
r+=l.count(4)
r+=twos//2
remtwos=twos%2
if(ones==threes):
    r+=ones+remtwos
elif(ones>threes):
    r+=threes
    tmo=ones-threes
    if(ones-threes<=2):
        r+=1
    elif(ones-threes>2 and remtwos==1):
        r+=1
        tmo-=2
        if(tmo%4!=0):
            r+=tmo//4+1
        else:
            r+=tmo
    else:
        if(tmo%4==0):
            r+=tmo//4
        else:
            r+tmo//4+1
        
    
else:
    r+=ones
    r+=(threes-ones)+remtwos
print(abs(r))


        
        
