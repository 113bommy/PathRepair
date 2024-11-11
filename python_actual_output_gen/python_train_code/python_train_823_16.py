N=list(0 for i in range(3))
p=list()
for i in range(3):
    p.append(input())
for i in range(3):
    for j in range(3):
        if p[i]==p[j]:continue
        else: 
            if p[i]=="rock" and p[j]=="scissors":N[i]+=1
            elif p[i]=="scissors" and p[j]=="paper":N[i]+=1
            elif p[i]=="paper" and p[j]=="rock":N[i]+=1
m=max(N)
for i in range(3):
    if N.count(N[i])==1 and N[i]==m :
        if i==0:print("F")
        elif i==1:print("M")
        elif i==2:print("M")
        exit()
print("?")