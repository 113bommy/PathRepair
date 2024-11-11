a = str(input())
a1 = a.split(" ")
k = int(a1[0])
n = int(a1[1])
w = int(a1[2])
v = 0
while w!= 0:
    v = w*k+v
    w -= 1
if n>v:
    print(0)
elif v>n:
    print(v-n)
