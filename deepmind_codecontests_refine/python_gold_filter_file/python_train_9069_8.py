s=input()
horizontal=-1
vertical=-1
v=[]
h=[]
for i in range(len(s)):
    if s[i]=="0":
        vertical+=1
        vertical%=2
        if vertical==0:ans=1
        else:ans=3
        print(ans,1)
    else:
        horizontal+=1
        horizontal%=4
        print(horizontal+1,2)
