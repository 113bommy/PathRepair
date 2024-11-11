t = int(input())
for i in range(t):
    n = int(input())
    ai = list(map(int,input().split()))
    ans = []
    for i in range(n//2):
        if ai[i] == ai[i+1]:
            ans += [ai[i],ai[i]]
        else:
            ans += [0]
    print(len(ans))
    print(" ".join(map(str,ans)))
    

