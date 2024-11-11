for _ in range(int(input().strip())):
    cols = int(input().strip())
    # matrix = []
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    # for i in range(2):
    #     matrix.append(list(map(int, input().strip().split())))


    l,u,ans =0,sum(a),1e9
    for i in range(cols):
        # path = max(sum(matrix[1][:i]),sum(matrix[0][i+1:]))
        # ans = min(path, ans)
        # if ans>path:
        #     ans = path
        u -= a[i]
        ans = min(ans, max(u,l))
        l+=b[i]

    print(ans)    

  
    
