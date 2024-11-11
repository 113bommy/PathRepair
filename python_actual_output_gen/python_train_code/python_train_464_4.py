#Proti letter shurur age ki obostha ache shei hisab korte hobe
#Ki obostha ache sheita khujar jonno (Age joto jon shuru - age jotojon sesh)

temp=input().split(" ")
n=int(temp[0])
k=int(temp[1])
s=input()
alphabet=set(s)
starts=[]
ends=[]

for x in alphabet:
    starts.append(s.index(x))
    ends.append(s.rindex(x))
res=0
for x in ends:
    count=0
    for y in starts:
        if y<x:
            count+=1


    for y in ends:
        if y<x:
            count-=1

    if count>k:
        res=1
if res:
    print("YES")
else:
    print("NO")