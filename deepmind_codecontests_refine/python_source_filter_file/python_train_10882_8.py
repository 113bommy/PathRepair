a,b=input().split()
a=int(a)
b=int(b)
h=[0]*10000000
l=list(map(int,input().split()))
for i in range(len(l)):
    if l[i]<len(h):
        h[l[i]]+=1
sum=0
i=1
p=[]
for i in range(1,b):
    if h[i]:
        continue
    else:
        if  (sum+i > b):
            break
        sum += i;
        h[i]+=1
        p.append(i)

print(len(p))
p=map(str,p)
print(" ".join(p))
    
                    
    
        
    
