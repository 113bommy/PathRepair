t = int(input())
while(t):
    t -= 1
    n = int(input())
    s1 = list(input())
    s2 = list(input())
    ans = []
    for i in range(n-1,-1,-1):
        if(s1[i]!=s2[i]):
            if(s1[i] == s2[0]):
                s2[0] = "0" if s2[0]=="1" else "1"
                ans.append(1)
            for j in range(i, i//2, -1):
                s2[j],s2[i-j] = s2[i-j],s2[j]
            for j in range(i, -1, -1):
                s2[j] = "0" if s2[j]=="1" else "1"
            ans.append(i+1)
    if(s2[0] != s1[0]):
        s2[0] = "0" if s2[0]=="1" else "1"
        ans.append(1)
    print(len(ans), *ans)
            