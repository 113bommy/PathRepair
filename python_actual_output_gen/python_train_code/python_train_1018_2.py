i,o,t,j,l,s,z=map(int,input().split())
a=(i//2+j//2+l//2)*2
print([a,max(a,((i-1)//2+(j-1)//2+(l-1)//2)*2+3)][i and j and l]+o)