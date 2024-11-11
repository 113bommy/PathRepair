o=input().rstrip().split(' ')
p=input().rstrip().split(' ')
if int(o[0])==int(o[1]):
    print(0)
elif int(o[1])==1:
    print(int(p[len(p)-1]) - int(p[0]))
else:
    l=[]
    G=0;
    for i in range(0,len(p)-1):
        if (1):
            l.append(int(p[i+1]) - int(p[i]))
    l.sort(key=int)
    for i in range(0,len(p)-int(o[1])):
        G+=int(l[i])
    print(G)
