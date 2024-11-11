t = int(input())
for i in [0]*t:
    n = int(input())
    if n%2:
        print('c' + 'a'*(n//2-1) + 'b' + 'a'*(n//2))
    else:
        print('a'*(n//2-1) + 'b' + 'a'*(n//2))