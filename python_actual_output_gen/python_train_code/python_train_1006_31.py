x=int(input())

lst=[]
for i in range(x): 
    n=input()
    lst.append(n)

for i in lst : #iklafkldskflsfjkldskk
    if len(i[1:-1])>=10 : 
        print(i[0]+str(len(i[1:-1]))+i[-1])
    else:
        print(i)