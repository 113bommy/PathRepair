numsLine=input()
numsLine=numsLine.split()
k=int(numsLine[0])
n=int(numsLine[1])
seq=input()
seq=seq.split()
dic=["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","Aa","Ba","Ca","Da","Ea","Fa","Ga","Ha","Ia","Ja","Ka","La","Ma","Na","Oa","Pa","Qa","Ra","Sa","Ta","Ua","Va","Wa","Xa"]
names=[]

for i in range(k):
    names.append(dic[i])

base=100
for i in range(len(seq)):
    if seq[i]=="YES":
        base=i
        break

if base==100:
    for i in range(1,k):
        names[i]=names[0]
else:
    for i in range(base+1,len(seq)):
        if seq[i]=="NO":
            names[n-1+i]=names[i]

    for i in range(0,base):
        names[i]=names[base]

print (" ".join(names))
