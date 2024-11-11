n=int(input())
l=list(map(int,input().split()))
counter=0
for j in l:
    if l.count(j)==2:
        l.remove(j)
        l.remove(j)
        
l=sorted(l)
print(l)
for i in range(0,len(l)-1,2):
    
        while l[i]!=l[i+1]:
          l[i]=l[i]+1
          counter+=1
print(counter)

        
    
    
