a,b=map(int,input().split())
lst=[]
lst1=[]
sum=0
sum1=0
sum2=0
for i in range(1,7):
    s=i-a
    lst.append(abs(s))
    s1=i-b
    lst1.append(abs(s1))
for j in range(len(lst)):
    if lst[j]==lst1[j]:
        sum=sum+1
    elif lst[j]>lst1[j]:
        sum1=sum1+1
    elif lst[j]<lst1[j]:
        sum2=sum2+1
print(sum1,sum,sum2)
