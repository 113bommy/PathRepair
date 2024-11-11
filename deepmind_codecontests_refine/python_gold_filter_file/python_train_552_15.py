ar = []
for i in input().split(' '):
    ar.append(int(i))
matrix = []
my_dict = {}
for i in range(ar[0]):
    temp = []
    for i in input().split(' '):
        temp.append(int(i))
    matrix.append(temp)
    if str(temp[0]) + ' ' + str(temp[1]) in my_dict:
        my_dict[str(temp[0]) + ' ' + str(temp[1])] = my_dict[str(temp[0]) + ' ' + str(temp[1])] + 1
    else:
        my_dict[str(temp[0]) + ' ' + str(temp[1])] = 1
matrix = sorted(matrix,key=lambda x: (x[0],-x[1]), reverse = True)
print(my_dict[str(matrix[ar[1] - 1][0]) + ' ' + str(matrix[ar[1] - 1][1])])
