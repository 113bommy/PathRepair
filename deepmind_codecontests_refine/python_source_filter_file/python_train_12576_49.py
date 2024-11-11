n=int(input())
a,b,ba,ans=0,0,0,0
for _ in range(n):
    s=input()
    for i in range(len(s)-1):
        if s[i]=="A" and s[i+1]=="B": ans+=1
    if s[0]=="B": b+=1
    if s[-1]=="A": a+=1
    if s[0]=="B" and s[-1]=="A": ba+=1
if ba==b==a: ans-=1 
print(ans+min(a,b))