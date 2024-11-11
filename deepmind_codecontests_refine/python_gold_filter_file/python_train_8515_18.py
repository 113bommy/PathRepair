N,K = map(int,input().split())
s=input()
if '0' not in s:
    print(len(s))
else:
    s2 = [0]
    count = 0
    for i in range(len(s)-1):
        count += 1
        if s[i] != s[i+1]:
            s2.append(count)
    s2.append(count+1)
    if s[0] == '0':
        s2.insert(0,0)
    ans = 0
    for i in range(0,len(s2)-1,2):
        ans = max(ans,s2[min(len(s2)-1,i+2*K+1)] - s2[i])
    print(ans)