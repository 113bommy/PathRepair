N=int(input())
plus=[]
minus=[]
for _ in range(N):
    S=input()
    tmp=0
    min_tmp=0 #)))の
    for i in range(len(S)):
        if S[i]=="(":
            tmp+=1
        else:
            tmp-=1
        if tmp<0:
            min_tmp=min(min_tmp,tmp)
    tmp=0
    max_tmp=0 #(((の
    for i in range(len(S)):
        i=len(S)-i-1
        if S[i]=="(":
            tmp+=1
        else:
            tmp-=1
        if tmp>0:
            max_tmp=max(max_tmp,tmp)
    if tmp>=0:
        plus.append((tmp,max_tmp,-min_tmp))
    else:
        minus.append((tmp,max_tmp,-min_tmp))

plus.sort(key=lambda x:x[2])
minus.sort(reverse=True,key=lambda x:x[1])
ans=0
for i,j,k in plus:
    if ans<k:
        print("No")
        exit()
    ans+=i
for i,j,k in minus:
    if ans<k:
        print("No")
        exit()
    ans+=i
if ans==0:
    print("Yes")
else:
    print("No")
