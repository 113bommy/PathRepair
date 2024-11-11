N=int(input())
S=[]
L=0
R=0
for i in range(N):
    s=input()
    n=len(s)
    data=[s[j] for j in range(n)]
    l=0
    r=0
    yabai=float("inf")
    for j in range(n):
        l+=(s[j]=="(")
        r+=(s[j]==")")
        yabai=min(l-r,yabai)
    S.append([yabai,l-r])
    L+=l
    R+=r

if L!=R:
    print("No")
else:
    first=[]
    last=[]
    for i in range(N):
        yabai,gap=S[i]
        if gap>0:
            first.append(S[i])
        else:
            last.append([gap-yabai,yabai])
    first.sort(reverse=True)
    last.sort(reverse=True)
    G=0
    for i in range(len(first)):
        yabai,gap=first[i]
        if 0>G+yabai:
            print("No")
            exit()
        else:
            G+=gap
    for j in range(len(last)):
        gapminus,yabai=last[j]
        if 0>G+yabai:
            print("No")
            break
        else:
            G+=gapminus+yabai
    else:
        print("Yes")
