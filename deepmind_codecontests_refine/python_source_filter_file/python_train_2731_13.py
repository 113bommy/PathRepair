def list_to_str(liste):
    a=""
    for i in liste:
        a=a+str(i)
    return a

for i in range(int(input())):
    matrix=[]
    for i in range(9):
        arr=[]
        for i in input():
            arr.append(i)
        matrix.append(arr)
    for i in matrix:
        for j in range(9):
            if i[j]==1:
                i[j]=2
    for i in matrix:
        print(list_to_str(i))