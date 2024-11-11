a=int(input())
sa=input().split(' ')
sa2=[]
for element in sa:
    sa2.append(int(element))

sa2.sort()
total=0
months=0
sa2.reverse()
if sum(sa2)<=a:
    print(-1)
else:
    
    while total<a and months<=12:
        total+=sa2[0]
        sa2.remove(sa2[0])
        months+=1
    print(months)
