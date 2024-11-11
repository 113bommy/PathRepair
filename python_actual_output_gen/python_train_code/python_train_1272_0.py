def parser():
    return [int(x) for x in input().split(" ")]    
#Recibiendo n y m
n,m=parser()
#Recibiendo los colores de los vertices
colors_vertices=parser()
upper=max(colors_vertices)

sets=[set() for x in range(upper+1)]

for i in range(m):
    edge=parser()
    color1=colors_vertices[edge[0]-1]
    color2=colors_vertices[edge[1]-1]
    if color1!=color2:
        sets[color1].add(color2)
        sets[color2].add(color1)

max=len(sets[0])
color=0
for i in range(upper):
    if max<len(sets[i]):
        max=len(sets[i])
        color=i
    
if max==0:
    print(min(colors_vertices))
else:
    print(color)