n=int(input())
s=input()
r=s.count(".")
ans=[]
for i in s:
    if i=="#":
        r+=1
    else:
        r-=1
    ans.append(r)
print(min(ans))