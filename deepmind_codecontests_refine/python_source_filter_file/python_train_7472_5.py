n=int(input())
A=[]
for i in range(n):
    s=input()
    l=0
    o=0
    for c in s:
        if c=='(':
            l+=1
        else:
            l-=1
            o=min(o,l)
    A.append((l,o))
A.sort(key=lambda x:-10**9 if x[1]==0 else x[1] if x[0]>=0 else 10**7+x[1]-x[0])
last=0
for l,o in A:
    if last+o<0:
        print("No")
        exit(0)
    last+=l
print("Yes" if last==0 else "No")