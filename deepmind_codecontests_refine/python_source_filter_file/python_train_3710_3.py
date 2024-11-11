h1, a1, c1=map(int, input().split())
h2, a2=map(int, input().split()); d=[]; x=0
while h2>0:
    if h2<a1:
        d.append('STRIKE')
        h2-=a1
        x+=1
    else:
        if h1-a2<=0:
            d.append('HEAL')
            x+=1
            h1+=c1-a2
        
        else:
            h2-=a1
            d.append('STRIKE')
            h1-=a2
            x+=1
        
print (x)
for  t in range(x):
    print (d[t])
