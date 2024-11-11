def substring(s):
    firstc=s[0]
    score=1
    l=1
    for i in s[1:]:
        if i==firstc:
            score+=1
            l+=1
        else:
            break
    lastc=s[-1]
    score+=1
    r=1
    for i in s[len(s)-2::-1]:
        if i==lastc:
            score+=1
            r+=1
        else:
            break
    if lastc==firstc:
        return ((r+1)*(l+1))%(998244353  )
    else:
        return (score+1)%(998244353  )

a=input()
print(substring(input()))