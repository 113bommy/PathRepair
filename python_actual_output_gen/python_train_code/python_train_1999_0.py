t,sx,sy,ex,ey=map(int,input().split())
s=input()
ans=-1
for i in range(len(s)):
    if s[i]=='E' and sx< ex:
        sx+=1
    if s[i]=='W' and sx>ex:
        sx-=1
    if s[i]=='N' and sy<ey:
        sy+=1
    if s[i]=='S' and sy>ey:
        sy-=1
    if sx==ex and sy==ey:
        ans+=(i+1)
        break
print(ans)
        
        

    