s=input()
N=len(s)
alpha="abcdefghijklmnopqrstuvwxyz"
a=[0]*26
for i in range(N):
    for j in range(26):
        if s[i]==alpha[j]:
            a[j]+=1
            break

if s=="zyxwvutsrqponmlkjihgfedcba":
    print(-1)
    exit()
c=0
lastidx=-1
while True:


    for j in range(lastidx+1,26):
        if a[j]==0 :
            print(s[:c]+alpha[j])
            exit()
    lastidx=alpha.index(s[-1+c])
    a[lastidx] -= 1
    c-=1