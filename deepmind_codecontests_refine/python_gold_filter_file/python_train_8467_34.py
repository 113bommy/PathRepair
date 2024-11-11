loop = int(input())
e=[0,1]
sums = 0
i=2
while sums <loop:
    sums=e[i-1]+e[i-2]
    e.append(sums)
    i+=1
    
n=0
m=0
o=0
for i in range(len(e)-2):
    for j in range(i, len(e)-1):
        for k in range(j, len(e)):
            if e[i]+e[j]+e[k] == loop:
                n=e[i]
                m=e[j]
                o=e[k]

print(str(n)+" "+str(m)+ " " +str(o))