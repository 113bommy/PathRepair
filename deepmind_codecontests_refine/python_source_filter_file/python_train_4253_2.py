S=input()
X=[]
SS=""
cnt=0
for s in S:
    if s!='x':
        SS+=s
        X.append(cnt)
        cnt=0
    else:
        cnt+=1
X.append(cnt)
flag=True
for i in range(len(SS)//2):
    if SS[i]!=SS[-1-i]:
        flag=False
ans=0
for i in range(len(X)//2):
    ans+=max(X[i],X[-1-i])
if flag:
    print(ans)
else:
    print(-1)