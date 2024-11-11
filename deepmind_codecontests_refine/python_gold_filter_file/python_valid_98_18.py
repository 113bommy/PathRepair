t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    if len(set(s))==1:
        print(-1,-1)
    else:
        for i in range(1,n):
            if s[i-1]!=s[i]:
                print(i,i+1)
                break