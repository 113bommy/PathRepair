t = int(input())
a = []
for i in range(t):
    a.append(input())
for i in a:
    p=-1
    l=len(i)
    d=0
    for j in range(l):
        if i[j]=="1":
            q=j
            s=j-p-1
            while(q<l):
                if q==(j+14):
                    break
                f=int(i[j:q+1],2)
                r=q-j+1
                if (r+s)>=f:
                    d+=1
                q+=1
            p=j
    print(d)




