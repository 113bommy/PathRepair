NAME=str(input())
n=int(input())
lname=list();
lpoints=list();
tmplist=list()
lstr=str();
for i in range(n):
    lstr=str(input())
    lstr=lstr.replace("'s wall",''); lstr=lstr.replace("'s post",'')
    lstr=lstr.replace("ted on ",' ');
    tmplist=lstr.split(' ')
    if tmplist[0]==NAME or tmplist[2]==NAME:
        if tmplist[0]==NAME: lstr=tmplist[2]
        else: lstr=tmplist[0]
        action=tmplist[1]
        if action=='post':
            lname.append([lstr,15])
        elif action=='commen':
            lname.append([lstr,10])
        elif action=='likes':
            lname.append([lstr,5])
    else:
        lname.append([tmplist[0],0])
        lname.append([tmplist[2],0])
        
spnames=dict()
spnames={lname[i][0]:0 for i in range(len(lname))}
for i in range(len(lname)):
    spnames[lname[i][0]]=spnames[lname[i][0]]+lname[i][1]
invspnames=dict()
for key in spnames:
    val = spnames[key]
    if val not in invspnames: invspnames[val] = [key]
    else:invspnames[val].append(key)
lpoints=list(map(int,(invspnames.keys())))
lpoints.sort(); lpoints.reverse()
for i in lpoints:
    tmplist=list(map(str,invspnames.get(i)))
    tmplist.sort()
    for s in tmplist: print(s)
