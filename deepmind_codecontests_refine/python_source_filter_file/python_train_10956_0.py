import sys
input = sys.stdin.buffer.readline

t = int(input())

for i in range(t):
    a,b = list(map(int, input().split()))
    
    x = 2**(b - 1)
    zz = min(100, 2**(b - 1))
    
    middle = [j for j in range(x-zz, x+zz)]
    
    left = 0
    right = 0
    
    for j in range(a):
        s = input()
        s = int(s,2)
        if s in middle:
            middle.remove(s)
        elif s<min(middle):
            left += 1
        else:
            right += 1
            
    pos = (len(middle) - 1 - left + right) // 2
    ans = (middle[pos])
    ans = "{0:b}".format(ans)
    
    ans = '0' * (b-len(ans)) + ans
    print(ans)