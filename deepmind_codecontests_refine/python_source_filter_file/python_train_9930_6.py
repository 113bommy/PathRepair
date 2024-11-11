n,m = map(int,input().split())
if n==m or n==m+1:
    s = [0]*n
    for _ in range(m):
        a,b = map(int,input().split())
        s[a-1]+=1
        s[b-1]+=1
    s = set(s)
    if s=={2}:
        print('ring topology')
    elif s == {1, 2}:
        print("bus topolog")
    elif s == {1, m}:
        print("star topolog")
    else:
        print('unknown topology')
else:
    print('unknown topology')
    exit(0)
