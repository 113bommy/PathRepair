x=input()
count={}
for i in x:
    count[i]=count.get(i,0)+1
l=list(count.values())
t=0
for m in l:
    t+=m**2
print(t)