def swap(list1,i,j):
    list1[i],list1[j]=list1[j],list1[i]
    return list1

n=int(input());a=list(map(int,input().split()))
p=sorted(a);ans=[];i=0
while a!=p and i<n:
    j=a.index(a[i]);m=a.index(p[i]);a=swap(a,j,m);ans.append([j,m])
    i+=1
print(len(ans))
for it in ans:print(*it)