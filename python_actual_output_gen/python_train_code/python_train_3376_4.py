t=input()
for _ in range(int(t)):
    n=int(input())
    s=input()
    mn=2000
    ind=[]
    for i in range(n):
        if ord(s[i])<mn:
            mn=ord(s[i])
            k=i+1
    for i in range(n):
        if ord(s[i])==mn:
            ind.append(i)
    ans='z'*n
    for i in range(len(ind)):
        j=ind[i]+1
        if j==(n-1):
            temp=s[::-1]
        else:
            if (n%2==0 and j%2==1) or (n%2==1 and j%2==0):
                temp=s[j-1::]+s[0:j-1:]
            else:
                temp=s[j-1::]+s[0:j-1:][::-1]
        if temp<ans:
            ans=temp
            k=j
    print(ans)
    print(k)