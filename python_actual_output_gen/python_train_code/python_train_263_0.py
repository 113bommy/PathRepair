n = int(input())
angles = [ int(input()) for _ in range(n) ]
pos = sum(angles)//2
def check(i, sm=0):
    if i>=n: return False
    elif i==n-1 and ( (sm+angles[i]) % 360 == 0 or (sm-angles[i]) % 360):
        return True
    elif check(i+1, sm+angles[i]):
        return True
    elif check(i+1, sm-angles[i]):
        return True
    else:
        return False
if check(1, sm = angles[0]) or check(1, -1*angles[0]):
    print('YES')
else:
    print('NO')