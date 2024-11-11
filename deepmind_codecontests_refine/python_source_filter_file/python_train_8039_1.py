def callps(s):
    n=len(s)
    lps=[]
    for i in range(n):
        lps.append(0)
    i=1
    l=0
    while(i<n):
        if(s[i]==s[l]):
            l+=1
            lps[i]=l
            i+=1
        else:
            if(l!=0):
                l=lps[l-1]
            else:
                lps[i]=0
                i+=1
    return max(lps)
def fun(s):
    n=len(s)
    if(n==1):
        return s
    for i in range(n//2):
        if(s[i]!=s[n-i-1]):
            break
    res=s[:i]
    s=s[i:n-i]
    premid=s[:callps(s+"#"+s[::-1])]
    postmid=s[::-1][:callps(s[::-1]+"#"+s)]
    if(len(postmid)>len(premid)):
        mid=postmid
    else:
        mid=premid
    res=res+mid+res[::-1]
    return res
t=int(input())
while(t):
    t-=1
    s=input()
    print(fun(s))