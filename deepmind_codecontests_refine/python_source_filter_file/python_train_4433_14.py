n=int(input())
s=list(input())

nNum=[0,0,0,0,0]
nEl=['A','G','C','T','?']
nA=0
nG=0
nC=0
nT=0
nQQ=0
pos=[]
done=[]
for i in range(n):
    if s[i]=='?':
        pos.append(i)
        nNum[4]+=1
    else:
        for j in range(4):
            if s[i]==nEl[j]:
                nNum[j]+=1
print(nNum[3])
if n%4!=0 or nNum[0]>n/4 or nNum[1]>n/4 or nNum[2]>n/4 or nNum[3]>n/4:
    print('===')
else:
    for j in range(4):
        for i in range(int(n/4)-nNum[j]):
            if pos!=[]:
                s[pos[0]]=nEl[j]
                pos.pop(0)
                #print(pos)
    s=''.join(s)
    print(s)
        
