n=input()
ans=0
chk=n
for i in range(len(n)):
    chk=chk[-1]+chk[:-2]
    if chk!=n:
        ans+=1
    else:
        break
print(ans)