data=input().split()
data=[int(data[i]) for i in range(0,3)]
students=data[0]
pen=data[1]
notebooks=data[2]
if students>=pen and students>=notebooks:
    print('YES')
else:
    print('NO')