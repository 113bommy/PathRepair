a,b,c,d,e = input('').split(' ')
s = int(a)
v1 = int(b)
v2 = int(c)
t1 = int(d)
t2 = int(e)
j = s * v1 + t1 * 2
k = s*v2 + t2 * 2
if j > k:
    print("First")
elif j < k:
    print("Second")
else:
    print('Friendship')