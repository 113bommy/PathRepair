n=input()
n=n.split()
print(n)
a=int(n[0])
if a-int(n[1])<=0 and a-int(n[2])<=0:
    print('YES')
else:
    print('NO')