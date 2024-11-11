[n,a,b] = [int(n) for n in input().split(" ")]
w = input()

found = False
for i in range(0,int(n/a)):
    if (n-a*i)%b == 0:
        found = True
        p = i
        q = int((n-a*i)/b)
        print(p+q)
        for j in range(0,p):
            print(w[a*j:a*(j+1)])
        for k in range(0,q):
            print(w[a*p+b*k:a*p+b*(k+1)])
        break
    
if not found:
    print(-1)        
