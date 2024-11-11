for _ in range(int(input())):
    n = int(input())
    curr = '('*n + ')'*n 
    print(curr)
    for i in range(1,n):
        curr = '()'*i + '('*(n-i) + ')'*(n-i)
        print(curr)
        