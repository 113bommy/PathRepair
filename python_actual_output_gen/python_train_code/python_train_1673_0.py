n=input()
d=dict()
empty=[]
for i in range(int(n)):
    s=input()
    for c in s:
        if c in d:
            d[c]+=1
        else:
            d[c]=1
    empty.append(s)

#print(empty)

m=-1
for i in range(97,123):
    for j in range(97,123):
        #global m
        ans=0
        if j<=i or d.get(chr(i),-1)==-1 or d.get(chr(j),-1)==-1:
            continue;
        for k in range(len(empty)):
            flag=0
            for c in empty[k]:
                if c!=chr(i) and c!=chr(j):
                    flag=1
                    break;
            if flag==0:
                ans+=len(empty[k])
        #print('ans%s' %ans)
        #print('m%s' %m)
        if m<ans:
            m=ans

print(m)

        
