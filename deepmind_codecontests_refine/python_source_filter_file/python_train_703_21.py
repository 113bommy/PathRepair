N,M=map(int,input().split())
SC=[input().split() for _ in range(M)]
ans=["0"]*N
for s,c in SC:
  if ans[int(s)-1]!="0" and ans[int(s)-1]!=c:
    print(-1)
    exit()
  if int(s)==1 and c=="0":
    print(-1)
    exit()
  ans[int(s)-1]=c
if N>1 and ans[0]=="0":
  ans[0]="1"
print("".join(ans))