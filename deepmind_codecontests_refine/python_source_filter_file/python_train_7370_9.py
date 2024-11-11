(n,),*a=[[*map(int,i.split())]for i in open(0)]
d={}
for i,j in a:
    for x,y in a:
        if i!=x or j!=y:
            d[(i-x,j-y)]=d.get((i-x,j-y),0)+1
print(n-max(d.values()))