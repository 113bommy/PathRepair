slist = input()
tlist = input()
scounter = 0
slength=len(slist)
slist=slist+slist
preposition=-1
for tchar in tlist:
    preposition=slist.find(tchar, preposition+1)
    if preposition==-1:
        scounter=-1
        break
    elif preposition>slength:
        scounter+=slength
        preposition-=slength
    # print(tchar, scounter, preposition)
if (scounter==-1):
    print(scounter)
else:
    print(scounter+preposition+1)