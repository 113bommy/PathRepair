a,b=[],
for z in[*open(0)][1:]:x,y=map(int,z.split());a+=x+y,;b+=x-y,
print(max(abs(max(a)-min(a)),abs(max(b)-min(b))))