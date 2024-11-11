n=int(input())
s=[0 for i in range(n)]
t = 1
for i in range(1, n, 2):
    s[i]=t
    t += 1
for i in range(0, n, 2):
    s[i]=t
    t += 1
if n<2:
    print(0)
elif n==3:
    print('2\n1 3')
else:
    print(n, ' '.join(map(str, s)), sep='\n')