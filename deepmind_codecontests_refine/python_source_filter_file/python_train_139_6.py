list1=[]
homelist=[]
awaylist=[]
sol=[]
for item in range(int(input())):
    y=input().split()
    for a in y:
        list1.append(int(a))
list2=list(enumerate(list1))
for a,b in list2:
    if a%2==0:
        homelist.append(b)
    else:
        awaylist.append(b)
for p in homelist:
    for q in awaylist:
        if p==q:
            sol.append((p,q))
len(sol)      