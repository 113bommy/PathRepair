n=int(input())

rbg=list(input())

colors=['R','B', 'G']
mincount=10**8
minrbg=[]

for c in colors:
    newcolors=[]
    for a in colors:
        if not a==c:
            newcolors.append(a)
    for b in newcolors:
        
        for lastcolor in newcolors:
            if not lastcolor==b:
                 d=lastcolor
        count=0
        newrbg=[]
        for i in range(n):
            if i%3==0:
                newrbg.append(c)
                if not rbg[i]==c:
                    count+=1
            if i%3==1:
                newrbg.append(b)
                if not rbg[i]==b:
                    count+=1
            if i%3==2:
                newrbg.append(d)
                if not rbg[i]==d:
                    count+=1
        if count<=mincount:
            mincount=count
            minrbg=newrbg

    
print(mincount)
print(*minrbg)