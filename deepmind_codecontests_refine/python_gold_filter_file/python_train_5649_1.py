from sys import stdin
t=  int(input())
while(t>0):
    s = input()
    #s=  list(s)
    arr = []
    d = {}
    curr = 0
    for i in range(len(s)):
        if s[i]=='-':
            curr -=1
            if curr  not in d:
                d[curr]=i+1
        else:
            curr+=1
    ans = 0
    for i in range(1,10**6+5):
        if -i in d:
            ans+=d[-i]
        else:
            ans+=len(s)
            break
    print(ans)         
    t-=1