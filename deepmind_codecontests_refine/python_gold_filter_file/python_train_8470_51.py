s=int(input())
for i in range(s+1,s+2000):
    l=[]
    c=str(i)
    for j in c:
        if j not in l:
            l.append(j)
    ans="".join(l)
    if(int(ans)>int(s)):
      break
print(ans)
        
    

