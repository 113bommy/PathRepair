string=str(input())
astring=str(input())+' '

word=''
alist=[]
n=int(string[:string.index(' ')])
k=int(string[string.index(' ')+1:])

for char in astring:
    if char!=' ':
        word+=char
    else:
        alist.append(int(word))
        word=''

minchange=n
mina=1000

for a in range(1,1001):
    blist=[x*k+a for x in range(0,n)]
    change=0

    for i in range(0,n):
        if alist[i]!=blist[i]:
            change+=1

        if change>=minchange:
            break

    if change<minchange:
        minchange=change
        mina=a

blist=[x*k+mina for x in range(0,n)]
changelist=[]

for i in range(0,n):
        if alist[i]>blist[i]:
            changelist.append('- '+str(i+1)+' '+str(alist[i]-blist[i]))
        elif alist[i]<blist[i]:
            changelist.append('+ '+str(i+1)+' '+str(blist[i]-alist[i]))

print(minchange)

if minchange>0:
    for change in changelist:
        print(change)