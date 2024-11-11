n=input()
q,o=len(n),11
for i in range(1,int(int(n)**.5)+1):
    i=i**2
    w,d,t,r=len(str(i)),str(i),0,1
    for j in range(w):
        for k in range(r,q):
            if d[j]==n[k]:t+=1;r=k;break
    if t==w:o=min(o,q-t)
print([-1,o][o!=11])