for _ in range(int(input())):
    n = int(input())
    curr = '('*n + ')'*n 
    print(curr)
    for i in range(1,n):
        curr = '()'*i + '('*(n-1) + ')'*(n-1)
        print(curr)
        