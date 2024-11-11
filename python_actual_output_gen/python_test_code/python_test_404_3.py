T = int(input())
for i in range(T):
    n,k = map(int,input().split())
    s = ['a']*n
    for j in range(n-2,0,-1):
        if k <= (n-j-1):
            s[j] = 'b'  #LEFTMOST ELEM   'b'
            s[n-k] = 'b'  #RIGHTMOSTELEM  'b'
            print(''.join(s))
            break
        k -= n-j-1
