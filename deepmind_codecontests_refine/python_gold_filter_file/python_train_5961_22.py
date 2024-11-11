x=y=0
n=int(input());z=[]
for i in range(n+1):z+=[[x,y],[x-1,y],[x,y-1]];x-=1;y-=1
z+=[[x,y]]
print(len(z))
for i in z:
    print(*i)