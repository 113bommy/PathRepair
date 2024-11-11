# cook your dish here
# cook your dish here
n=int(input())
l=list(input().split())
l1=[]
for i in l:
    i=set(i)
    i=list(i)
    i.sort()
    l1.append(i)
print(l1)
l1.sort()
c=0
for i in range(len(l1)-1):
    if(l1[i]!=l1[i+1]):
        c+=1
print(c+1)
    
    
        
            