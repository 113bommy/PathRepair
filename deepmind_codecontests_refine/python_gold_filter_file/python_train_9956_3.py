import bisect

def list_output(s):    
    print(' '.join(map(str, s)))
    
def list_input(s='int'):
    if s == 'int':
        return list(map(int, input().split()))    
    elif s == 'float':
        return list(map(float, input().split()))
    return list(map(str, input().split()))

[a, b, c] = list(map(int, input().split()))
cnt = 1
for _ in range(1000000):
    a *= 10
    d = a//b
    r = a%b
    if d == c:
        print(cnt)
        exit(0)
    a = r
    cnt += 1
print(-1)

