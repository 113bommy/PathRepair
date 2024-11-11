t=int(input())
for i in range(t):
    s=input()
    n=len(s)
    ans=[]
    for i in range(len(s)):
        if s[i]=="R":
            ans.append(i+1)
    if len(ans)==0:
        print(len(s)+1)
    else:
        fina=[]
        fina.append(ans[0]-0)
        fina.append(n+1-ans[-1])
        for i in range(1,len(ans)-1):
            fina.append((ans[i+1]-ans[i])+1)
        print(max(fina))