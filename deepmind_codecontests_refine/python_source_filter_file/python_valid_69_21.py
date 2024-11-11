l=[1]
for i in range(1,50):
    l.append(l[i-1]*2)
for i in range(int(input())):
    n=list(input())
    mx=1000
    for i in l:
        i=str(i)
        f=j=k=h=0
        while j<len(i) and k<len(n):
            if i[j]==n[k]:
                h+=1
            else:j-=1;f+=1
            k+=1
            j+=1
        if len(i)<len(n):
            f+=len(n)-k
        mx=min(mx,f+(len(i)-h))
    print(mx)
