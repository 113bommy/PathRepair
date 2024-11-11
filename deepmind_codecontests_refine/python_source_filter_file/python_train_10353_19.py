n=input()
l=[]
l=n.split(' ')
m=int(l[1])
main1=[]
for a in range(int(l[0])):
    b=[]
    y=[]
    c=input()
    y=c.split(' ')
    for i in range(int(y[0])):
        b.append(int(y[i+1]))
    main1.append(b)
p=[]
for x in range(len(main1)):
    if m>min(main1[x]):
        p.append(x+1)
p.sort()
if p!=[]:
    print (len(main1))
    for a in p:
        print (a,end=' ')
else:
    print (0)
                   
                   
            
    
