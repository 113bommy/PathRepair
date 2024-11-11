t=int(input())
if(t>36):
    print(-1)
else:
    a8=t//2
    a0=t%2
    print('8'*a8 + '0'*a0)
