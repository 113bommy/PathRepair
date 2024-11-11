k=ord('a')
for i in input():
    if ord(i)-k>1:
        print('NO')
        break
    if ord(i)>k:k+=1
else:
    print('YES')