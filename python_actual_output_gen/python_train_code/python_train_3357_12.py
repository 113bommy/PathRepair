n,k=list(map(int,input().split()))
p=list(map(int,input().split()))
tad=k
tom=(k-1)+0.5
lol=sum(p)
s=0
for x in range(5555):
    if (lol/n)>=tom:
        print(s)
        break
    else:
        n+=1
        if ((lol+k)/(n))<tom:
            k+=tad
            s+=1
        else:
            print(s+1)
            break
    