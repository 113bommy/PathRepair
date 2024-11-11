S=input()+"R"
RLs=[]
Rpos=0
for i in range(len(S)):
    if S[i]=="L" and S[i+1]=="R":
        RLs.append(S[Rpos:i+1])
        Rpos=i+1
ans=[]
for RL in RLs:
    i=RL.find("RL")
    l=len(RL)
    for _ in range(i):
        ans.append(0)
    x=(l-(i+1))//2+i//2+1
    ans.append(x)
    ans.append(l-x)
    for _ in range(l-i-2):
        ans.append(0)
print(ans)