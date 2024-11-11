a = list(input())
per = 0
if a == ['a'] * len(a):
    print('a' * (len(a) - 1) + 'b')
else:
    for i in range(len(a)):
        if a[i] == 'a':
            if per == 0:
                
                print('a', end = '')
            else:
                print(''.join(map(str, a[i:])))
                break
        else:
            per = 1
            print(chr(ord(a[i]) - 1), end = '')    