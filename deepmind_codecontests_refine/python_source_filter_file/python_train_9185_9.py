for _ in range(int(input())):
    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    a_d, b_d, ab_d = [0]*(2*k+1), [0]*(2*k+1), [0]*(2*k+1)

    for i in range(int(n/2)):
        a,b = l[i],l[n-i-1]
        a,b = min(a,b),max(a,b)
        a_d[a]+=1
        b_d[k+b-1]+=1
        ab_d[a+b-2]+=1

    val = n
    sol = n
    for i in range(len(ab_d)):
        val = val - a_d[i] + b_d[i]
        sol = min(val-ab_d[i], sol)
            
    print(sol)