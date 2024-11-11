s=input()
count={}
for c in s:
    count[c]=count.get(c,0)+1
l=list(count.values())
t=0
for i in l:
    t+=i*i
print(t)