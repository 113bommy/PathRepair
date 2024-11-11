n= int(input())

sen= input()

for i in range(1,n-1,1):

    if sen[i]>sen[i+1]:
        print('YES')
        print(i+1,i+2)
        exit(0)


print('NO')