c,k=map(int,input().split())
chst = input()
key =input()
e1=e2=o1=o2=0
for i in chst.split():
    if(int(i)%2==0):
        e1+=1
    else:
        o1+=1
for j in key.split():
    if(int(j)%2==0):
        e2=e2+1
    else:
        o2=o2+1
print(min(e2,e1)+min(o1,o2))