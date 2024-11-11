n,k = map(int, input().split())

mt = ((n-1)**2+(n-1)) / 2
if k > mt:
    print('no solution')
    exit()

ans = ['0 0\n']
for i in range(1, n-1):
    ans.append('1 %i\n' % (10*i*n))
ans.append('2 0')

print(''.join(ans))