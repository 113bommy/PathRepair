d={}
for _ in[0]*int(input()):
    i=input()
    d[i]=d.get(i,0)^1
print(sum(d.values()))