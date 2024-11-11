a=int(input())
z=list(map(int,input().split()))
if(a==1):
    print(0)
    exit()
odd=[]
eve=[]
for i in range(len(z)):
    if(i%2==0):
        odd.append(z[i])
    else:
        eve.append(z[i])

pre1=[odd[0]]
for i in range(1,len(odd)):
    pre1.append(pre1[-1]+odd[i])
for i in range(len(pre1)):
    pre1[i]-=z[2*i]

pre2=[eve[0]]
for i in range(1,len(eve)):
    pre2.append(pre2[-1]+eve[i])
for i in range(len(eve)):
    pre2[i]-=z[(2*i)+1]

c1=0
suf1=[sum(z[0::2])]
suf2=[sum(z[1::2])]
for i in range(1,len(odd)):
    suf1.append(suf1[-1]-z[2*(i-1)])
for i in range(1,len(eve)):
    suf2.append(suf2[-1]-z[(2*i)-1])

for j in range(len(z)):
    if(j%2==0):
        m=j//2
        if(m>=len(suf2) or m>=len(pre2)):
            continue;
        if(pre1[m]+suf2[m]==pre2[m]+suf1[m]-z[j]):
            c1+=1
           
    else:
        m=j//2
        
        if(pre1[m]+z[j-1]+suf2[m]-z[j]==pre2[m]+suf1[m]-z[j-1]):
            c1+=1
if(len(z)%2==1):
    if(sum(z[0::2])-z[-1]==sum(z[1::2])):
        c1+=1
print(c1)
