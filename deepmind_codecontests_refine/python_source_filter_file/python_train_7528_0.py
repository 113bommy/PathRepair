for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    def checker(brr):
        m = len(brr)
        for i in range(m):
            for j in range(i+1,m):
                for k in range(j+1,m):
                    if (arr[i]<=arr[j] and arr[j]<=arr[k]) or (arr[i]>=arr[j] and arr[j]>=arr[k]):
                        return False
        return True
    ans = 0
    for i in range(n):
        brr = []
        for j in range(i,n):
            brr.append(arr[j])
            if len(brr)<=2:
                ans+=1
                continue
            elif len(brr)>=5:
                break
            else:
                if checker(brr):
                    ans+=1
                else:
                    break
    print(ans)