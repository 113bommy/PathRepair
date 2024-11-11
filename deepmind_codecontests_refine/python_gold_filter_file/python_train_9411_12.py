a=[*map(int,input().split())]
s=sum(a)
if s%2 or any(s//2-j<0 for j in a):
    print('Impossible')
else:
    print(s//2-a[2],s//2-a[0],s//2-a[1])