for _ in range(int(input())):
    n = int(input())
    if n == 1:
        print('a')
        continue
    if n == 2:
        print('ab')
        continue
    if n == 3:
        print('abc')
        continue
    if n % 2 == 0:
        q = n//2-1
        print('a'*q+ 'b'+ 'a'*(q+1))
    else:
        q = n//2
        print('a'*q+ 'bc'+ 'a'*(q-1))