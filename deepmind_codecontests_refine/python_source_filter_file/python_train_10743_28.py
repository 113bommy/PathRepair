def solve() :
    inp = input().split()
    n = int(inp[0])
    m = int(inp[1])
    A = input().split()
    if(m < n) :
        print(-1)
        return
    suma = 0
    for a in A :
        suma += 2 * int(a)
    print(suma)
    for i in range(1, n) :
        print(i, i + 1)
    print(1, n)
    

t = int(input())

while(t > 0) :
    solve()
    t -= 1
    
