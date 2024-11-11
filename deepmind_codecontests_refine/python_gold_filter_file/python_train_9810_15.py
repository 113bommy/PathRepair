tc = int(input())
for _ in range(tc):
    n = int(input())
    s = str(input())
    ans = s
    op = 0
    for k in range(1 , n):
        t = ""
        if (n % 2) != (k % 2):
            t = s[k:] + s[0:k][::-1]
        else: 
            t = s[k:] + s[0:k]
        if t < ans:
            ans = t
            op = k
        #print(t)
    print(ans) 
    print(op+1)
   #print()