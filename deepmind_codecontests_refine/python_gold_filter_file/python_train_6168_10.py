t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    s=input()
    s=sorted(s)
    if k == n:
        print("".join(map(str,s[-1])))
    else:
        if s[0]==s[k-1]:
            ans=[s[k-1]]
            if s[k]==s[n-1]:
                times=(n-1-k+1)//k
                if (n-1-k+1)%k is not 0:
                    times += 1
                for i in range(times):
                    ans.append(s[k])
                print("".join(map(str,ans)))
            else:
                for i in range(k,n):
                    ans.append(s[i])
                print("".join(map(str,ans)))
        else:
            print(s[k-1])