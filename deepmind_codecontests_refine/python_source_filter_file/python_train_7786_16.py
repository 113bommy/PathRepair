s=int(input())

v=10**9

x=v-s%v

y=(s+x)//v

print('0 0 1000000000 1 {} {}'.format(x,y))