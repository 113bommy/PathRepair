(n, a, b) = map(int, input().split())
c = (a + 1) // 2
d = (b + 1) // 2
k = 0
while c != d:
    c = (c + 1) // 2
    d = (d + 1) // 2
    k += 1
    n = n // 2
    print(k,n,c,d)
k += 1
if n == 2:
    print('Final!')
else:
    print(k)
    
    
