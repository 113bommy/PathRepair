s = int(input())
v = 10**9
x = (v-s%v)%v
y = (s+x)//v
print(0,0,10**9,1,x, y)