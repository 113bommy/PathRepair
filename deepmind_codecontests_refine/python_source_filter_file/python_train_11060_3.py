for s in[*open(0)][1:]:n=int(s)//2;a=range(2,2*n+1,2);print(*(['YES']+[*a]+[i+(-1)**i
for i in a],['NO'])[n%2])