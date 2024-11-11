d={"chest":0,"biceps":0,"back":0}
n=int(input())
p=input()
l=p.split()
for i in range(n):
    if i%3==0:
        d["chest"]+=int(l[i])
    elif i%3==1:
        d["biceps"]+=int(l[i])
    elif i%3==2:
        d["back"]+=int(l[i])
key_max = max(d.keys(), key=(lambda k: d[k]))
print(key_max)
print(d)
    
