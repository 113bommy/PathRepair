def Solve(n, x, y):
    if n == 2:
        print(x, y)
        return
        
    if y <= n:
        s = ""
        for i in range(1, n+1):
            s += str(i)+" "
        print(s)
    else:
        k = y-x
        for i in range(1, 50):
            if k%i == 0 and (k//i)<= n-1:
                break
        arr = [x]
        r = k//i-1
        # print("diff=", k,"pos=", r, "mult=",i)
        if r+2== n:
            for c in range(r):
                arr.append(x+((c+1)*i))
            arr.append(y)
            l = len(arr)
            for c in range(n-l):
                arr.insert(0, x-((c+1)*i))
        else:
            c = 1
            l = len(arr)
            while(x-(c)*i > 0 and l < n-r-1):
                arr.insert(0, x-((c)*i))
                c += 1
                l += 1
            l = len(arr)
            for c in range(n-l):
                arr.append(x+((c+1)*i))
            # arr.append(y)
        s = ""
        for num in arr:
            s += str(num) + " "
        print(s)
 
for _ in range(int(input())):
    n, x, y = map(int, input().split())
    Solve(n, x, y)