x=int(input())

ans=0
if x%11>6:
    ans+=2
else:
    ans+=1

ans+=2*(x//11)
print(ans)