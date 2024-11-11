n=int(input())
l=list(map(int,input().split()))
l2=l.copy()
c=l.copy()
o=l.copy()
c.sort()
flag=1
cnt,var=0,0
# for i in range(0,(2*n)-1,2):
#     if l[i]>l[i+1]:var+=1
# if var>=(n//4):flag=1
# else:flag=0
while c!=l:
    # print("here")
    if flag:
        # print("here1")
        cnt+=1
        flag=1-flag
        for i in range((2*n)-1):
            if i%2==0:
                temp=l[i]
                l[i]=l[i+1]
                l[i+1]=temp
    else :
        cnt+=1
        flag=1-flag
        for i in range(n):
            temp=l[i]
            l[i]=l[n+i]
            l[n+i]=temp
    if o==l:break
cnt2=cnt
cnt=0
flag=0
while c!=l2:
    # print("here")
    if flag:
        # print("here1")
        cnt+=1
        flag=1-flag
        for i in range((2*n)-1):
            if i%2==0:
                temp=l2[i]
                l2[i]=l2[i+1]
                l2[i+1]=temp
    else :
        cnt+=1
        flag=1-flag
        for i in range(n):
            temp=l2[i]
            l2[i]=l2[n+i]
            l2[n+i]=temp
    if o==l2:break

if c==l and c==l2: print(min(cnt2,cnt))
else:print("-1")