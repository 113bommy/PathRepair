x=int(input())
s=0
i=1
d=[]
while s+i<=x:
    s+=i
    d.append(i)
    i+=1
print(i-1)
p=x-s
j=0
while j<p:
    d[len(d)-1-j%len(d)]+=1
    j+=1
print(*d)    
    