y=int(input())
ftprnt=input()
rlist=[]
llist=[]
for m,n in enumerate(ftprnt):
    if n=='R':
        rlist.append(int(m))
    if n=='L':
        llist.append(int(m))
if len(rlist)>0 and len(llist)>0:
    if min(rlist)<min(llist):
        print(min(rlist)+1,max(rlist)+1)
    else:
        print(min(llist)+1,max(llist)+1)
else:
    try:
        print(min(rlist)+1,max(rlist)+1)
    except:
        print(min(llist)+1,max(llist)+1)