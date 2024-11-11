s=str(input())
if len(set(s))==1:
    print(0)
else:
    l=len(s); n=l//2
    if s[:n]==s[n+1:][::-1]:
        print(l-1)
    else:
        print(l)




