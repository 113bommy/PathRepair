d={}
for _ in[0]*int(input()):
 i=input()
 d[i]=!d.get(i,0)
print(sum(d.values()))