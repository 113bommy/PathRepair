n,s=map(int,input().split())
lst1=list(input())
lst2=list(map(str,input().split()))
lst3=[]
for i in range(len(lst1)):
    if lst1[i] not in lst2:
        lst3.append(0)
    else:
        lst3.append(1)
lst4=[]
count=0
sum1=0
for i in range(len(lst3)):
    if lst3[i]==1:
        lst4.append(1)
    else:
        count=len(lst4)
        sum1+=count*(count+1)/2
        lst4=[]
count=len(lst4)
sum1+=count*(count+1)/2
print(sum1)