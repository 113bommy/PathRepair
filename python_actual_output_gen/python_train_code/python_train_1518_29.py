a=str(input())
b=str(input())
print(b)
if b.find(a[0])>-1:
    print('YES')
elif b.find(a[1])>-1:
    print('YES')
else:
    print('NO')