input = input()
n , k , t = input.split(' ')
n = int(n)
k = int(k)
t = int(t)
if t>k and t<n:
    print(k)
elif t<k:
    print(t)
else:
    print(k-(t-n))




