while(True):
    m,n = map(int,input().split())
    if not m: break
    a = list(range(1,m+1))
    b = [input() for _ in range(n)]
    t = [str(i+1) for i in range(n)]
    t[2::3]   = ["Fizz"]*len(t[2::3])
    t[4::5]   = ["Buzz"]*len(t[4::5])
    t[14::15] = ["FizzBuzz"]*len(t[14::15])
    i=0
    for j in range(n):
        if len(a) <2: break
        if b[j] != t[j]: del a[i]; i = i if i > len(a) else 0; continue
        i += 1
        i = i%len(a)
    print(" ".join(str(e) for e in a))
