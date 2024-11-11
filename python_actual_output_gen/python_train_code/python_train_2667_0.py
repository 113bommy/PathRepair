a=[]
for s in [*open(0)][1:]:a+=[*map(int,s.split())]
print(sum(a.count(x)<2 for x in range(1,len(a)+2)))