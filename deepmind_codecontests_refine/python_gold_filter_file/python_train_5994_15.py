n=input()
ans=1
chk=n
for i in range(len(n)):
    chk=chk[-1]+chk[:-1]
    if chk!=n:
        ans+=1
    else:
        break
print(ans)