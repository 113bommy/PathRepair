# Main maut ko takiya, aur kafan ko chaadar banakar audhta hoon!

n=int(input())

d={}

for i in range(n):
    a=input().split()

    if a[0] not in d:
        d[a[0]]=[]
        for j in a[2:]:
            d[a[0]].append(j)
    else:
        for j in a[2:]:
            d[a[0]].append(j)

print(len(d.keys()))
for i in d.keys():
    a=[]
    b=d[i]
    j=0
    k=0

    while j<len(b):
        l=len(b[j])
        k=0
        while(k<len(b)):
            if j!=k:
                #print(j,k,b[j],b[k],l,b)
                if len(b[k])>=l:
            #        print(b[k][-1*l:],b[j])
                    if b[k][-1*l:]==b[j]:
                        b[j]="-1"
                        break

            k+=1

        j+=1
    a=[]
    for k in b:
        if k!="-1":
            a.append(k)
    print(i,len(a),*a)
