n=int(input())
l=[]
for i in range(1,11):
    l.append(n+i)
for i in range(0,len(l)):
    l[i]=str(l[i])
    if('8' in l[i]):
        print(i+1)
        break