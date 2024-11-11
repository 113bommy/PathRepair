n, k = map(int, input().split())
s = input()

a = s.index('G')
b = s.index('T')

i = a
ans = 'NO'
if b < a:
    
    while i - k >= 0 and i - k != '#':
        i -= k
        if s[i] == 'T':
            ans = 'YES'
else:
    
    while i + k < n and i + k != '#':
        i += k
        if s[i] == 'T':
            ans = 'YES'
            
print(ans)