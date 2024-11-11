t = int(input())
for tt in range(t):
    n,k=map(int,input().split())
    s = input()
    ans = []
    if s[0] == ')':
        for i in range(n):
            if s[i] == '(':
                ans.append([1,i+1])
                s = s[i::-1] + s[i+1:]
                break
    for i in range(1,(k-1)*2):
        if i%2==0:
            if s[i]!='(':
                for j in range(i+1,n):
                    if s[j] == '(':
                        ans.append([i+1,j+1])
                        s = s[:i] + s[j:i-1:-1] + s[j+1:]
                        break
        else:
            if s[i]!=')':
                for j in range(i+1,n):
                    if s[j] == ')':
                        ans.append([i+1,j+1])
                        s = s[:i] + s[j:i-1:-1] + s[j+1:]
                        break
    for i in range((k-1)*2,(n+k)//2+1):
        if s[i]!='(':
            for j in range(i+1,n):
                if s[j] == '(':
                    ans.append([i+1,j+1])
                    s = s[:i] + s[j:i-1:-1] + s[j+1:]
                    break
    print(len(ans))
    for i in ans:
        print(*i)
            



