n=int(input())
ans=0
L=[105,165,195]
for l in L:
    if n>=l:
        ans+=1
    else:
        break
print(ans)
