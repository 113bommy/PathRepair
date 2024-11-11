for _ in range(int(input())):
    n,k = map(int, input().split())
    count = 1
    while k-count>0:
        k -= count
        count += 1
    print('a'*(n-count-1) + 'b' + 'a'*(k-count) + 'b' + 'a'*(k-1))