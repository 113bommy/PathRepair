t = int(input())
for i in range(t):
    s = input()
    t = input()
    p = input()
    m=len(s)
    n=len(t)
    x = 'a'
    dic3 = {}
    for i in range(26):
        dic3[x] = 0
        x = chr(ord(x) + 1)
    for i in p:
        dic3[i] = dic3[i] +1
    i=0
    j=0
    flag=0
    while i< m  and j<n:
        if s[i]==t[j]:
            i=i+1
            j=j+1
        elif dic3[t[j]]>0:
            dic3[t[j]]=dic3[t[j]]-1
            j=j+1
        else:
            flag=1
            break
    if i==m and j==n:
        print("YES")
    elif j==n and i<m:
        print("NO")
    elif flag==1:
        print("NO")
    elif i==m and j<n:
        flag2=0
        for k in range(j,n):
            if dic3[t[k]]>0:
                dic3[t[k]]=dic3[t[k]]-1
            else:
                print("NO")
                flag2=1
                break
        if flag2==0:
            print("YES")


