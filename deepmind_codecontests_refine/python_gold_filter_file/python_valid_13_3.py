oa = ord('a')
def slv(n, m, k):
    ans = [[-1]*m for i in range(n)]
    # assume n even
    if k & 1:
        return None
    if k > (m//2)*n:
        return None
    cnt = 0
    for i in range(0,n,2):
        for j in range(0,m-1,2):
            hh = ((i//2)%2)*2+((j//2)%2)
            c1 = 2*hh
            c2 = 2*hh+1
            if cnt == k:
                #vert
                ans[i][j] = c1
                ans[i+1][j] = c1
                ans[i][j+1] = c2
                ans[i+1][j+1] = c2
            else:
                ans[i][j] = c1
                ans[i][j+1] = c1
                ans[i+1][j] = c2
                ans[i+1][j+1] = c2
                cnt += 2
    if m & 1:
        for j in range(0, n, 2):
            c = 8 if (j&2) else 9
            ans[j][m-1] = c
            ans[j+1][m-1] = c
    
    return ans





for _ in range(int(input())):
    n, m, k = [int(i) for i in input().split()]
    ans = []
    if n & 1:
        if k >= (m//2):
            ans = slv(n-1,m,k-(m//2))
            if ans is None:
                print('NO')
                continue
            lst = [-1]*m
            for i in range(0,m,2):
                c = 10 if (i & 2) else 11
                lst[i] = c
                lst[i+1] = c
            ans.append(lst)
        else:
            print('NO')
            continue
    else:
        ans = slv(n,m,k)
        if ans is None:
            print('NO')
            continue
    
    print('YES')
    for rw in ans:
        print(''.join(chr(p+oa) for p in rw))
