s = input()
l = list(s)
l.append(1)
#print(l)
l1 = []
c1,c = 1,1
for i in range(len(s)):
    if l[i]==l[i+1]:
        c1+=1
    else:
        l1.append([s[i],c1])
        c1=1
n = len(l1)
print(l1)
print(n)
i = 0
while n>i:
    #print(i)
    if i==n-1:
        if l1[i][1]>=2:
            print(l1[i][0]*2,end='')
        else:
            print(l1[i][0])
        exit()
    if l1[i][1]==1:
        print(l1[i][0],end='')
    elif l1[i][1]>=2 and l1[i+1][1]>2:
        print(l1[i][0]*2,end='')
        print(l1[i+1][0],end='')
        i+=1
    elif l1[i][1]>=2 and l1[i+1][1]==2:
        print(l1[i][0]*2,end='')
        print(l1[i+1][0],end='')
        i+=1
    elif l1[i][1]>=2 and l1[i+1][1]==1:
        print(l1[i][0]*2,end='')
    #print(i)
    i+=1