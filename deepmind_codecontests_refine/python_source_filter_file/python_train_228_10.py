for _ in range(int(input())):
    n,m=map(int, input().split())
    s=input()
    p=list(map(int, input().split()))
    ans=[0 for i in range(26)]
    for i in s:
        ans[ord(i)-ord('a')]+=1
    freq=[[0 for i in range(n+1)] for j in range(26)]
    for i in range(1,n+1):
        freq[ord(s[i-1])-ord('a')][i]+=1
        for j in range(26):
            freq[j][i]+=freq[j][i-1]
    for i in p:
        for j in range(26):
            ans[j]+=freq[j][i]
    print(ans)
        
            
    