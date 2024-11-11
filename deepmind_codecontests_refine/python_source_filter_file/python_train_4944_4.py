n=int(input())
ak = input().split(" ")
ak.remove(ak[0])
bk=input().split(" ")
bk.remove(bk[0])
c=0
d=0


for i in range(len(bk)):
    while (len(ak) > 0 and len(bk) > 0 and c<100):
        if(int(ak[i])>int(bk[i])):
            s=ak[i]
            ak.append(bk[i])
            ak.remove(ak[i])
            ak.append(s)
            bk.remove(bk[i])
            c=c+1

        else:
            t=bk[i]
            bk.append(ak[i])
            bk.remove(bk[i])
            bk.append(t)
            ak.remove(ak[i])
            c = c + 1

if(c>99):
    print(-1)
elif(len(ak)>len(bk)):
    print(c,1)
else:
    print(c,2)