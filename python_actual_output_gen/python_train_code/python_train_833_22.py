i=[*map(int,input().split())]
print(sum(1 for x,y,z in zip(i,i[1:],i[2:]) if x>y and z>y or x<y and z<y))