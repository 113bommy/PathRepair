t=int(input())
c=0
lst=[]
lst2=[]
while t:
    t-=1
    a,b=map(int,input().split())
    lst.append(a)
    lst2.append(b)
for i in range(len(lst)):
    if lst[i] not in lst2[i+1:] and lst[i] not in lst2[:i]:
        c+=1
print(c)