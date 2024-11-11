##a = list(map(int, input().split()))
##print(' '.join(map(str, res)))

def list_input():
    return list(map(int, input().split()))

[n, x] = list_input()
a = list_input()
s = sum(a)
if n-1+s == x:
    print('YES')
    exit(0)
print('NO')