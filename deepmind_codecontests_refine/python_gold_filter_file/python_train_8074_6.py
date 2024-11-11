n = int(input())
d = 1e9
x = n;y=n+1;z=n*(n+1)
if(x>d or y>d or z>d or n==1):
    print('-1')
else:
    print(x,y,z)