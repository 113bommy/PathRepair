l1=[]
for i in range(0,180):
    l1.append(180/(i+1))
for i in range(0,int(input())):
    n=int(input())
    flag=0
    for item in l1:
        if n%item==0 and item*(l1.index(item)-1)>=n:
            print(l1.index(item)+1)
            flag=1
            break
    if flag==0:
        print(-1)