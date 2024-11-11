n, k, d = [int(k) for k in input().split()]
base_rep = [[0 for _ in range(d)] for _ in range(n)]


if k**d  < n:
    print(-1)
else:
    for j in range(n):
        num = j
        i=0
        while num >= k**i:
           i+=1
        i-=1
        #print(i)
        while num:
            base_rep[j-1][i] = num//k**i
            num = num % k**i
            i -=1
    for i in range(d):
        s =""
        for j in range(n):
            s += str(base_rep[j][i]+1) + " "
        print(s)