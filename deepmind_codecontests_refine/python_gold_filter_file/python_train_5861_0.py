q = int(input())
for _ in range(q):
    n,k = map(int,input().split())
    s ="bca"
    t = ""
    t += "a"*k
    n=n-k
   # print(n)
    if n%3==0:
        t+=s*(n//3)
    else:
        p = n%3
      #  print(p)
        t+=s*(n//3)
        if p==1:
            t+="b"
        elif p==2:
            t+="bc"
    print(t)