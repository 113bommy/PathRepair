n=int(input())
for i in range(n//7+1):
    t=n-(i*7)
    if (t)%4==0:
        l=''.join(['7'*i])
        ll=''.join(['4'*(t//4)])
        print(''.join([ll,l]))
        break
else: print(-1)