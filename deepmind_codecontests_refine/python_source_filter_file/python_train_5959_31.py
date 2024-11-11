def solver(n, m, k):
    print(((n+m)+(n*m)-3))
    print(("U"*(n-1))+("L"*(m-1)),end="")
    
    dirc = "R"
    for i in range(n):
        if dirc == "R":
            print(("R"*(m-1))+("D"),end="")
            dirc = "L"
        else:
            print(("L"*(m-1))+("D"),end="")
            dirc="R"
    
    print()

n,m,k= map(int,input().split())
for _ in range(2*k):
    waste = input()

solver(n,m,k)
