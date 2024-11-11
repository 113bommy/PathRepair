import bisect

def list_output(s):    
    print(' '.join(map(str, s)))
    
def list_input(s='int'):
    if s == 'int':
        return list(map(int, input().split()))    
    elif s == 'float':
        return list(map(float, input().split()))
    return list(map(str, input().split()))

n = int(input())
a = int(input())
b = int(input())
for x in range(n):
    t = n - x*a
    if t >= 0 and t%b == 0:
        y = t//b
        print('YES')
        print(' '.join(map(str, [x, y])))
        exit(0)
print('NO')
    
