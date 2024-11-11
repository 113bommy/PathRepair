n = int(input())
list1 = [{0 for i in range(n)}for j in range(n)]
for i in range(n):
    list1[i]=input()

count = 0
if n<=2:
    print(0)
else:
    for i in range(1,n-1):
        for j in range(1,n-1):
            if list1[i][j] == 'X':
                if list1[i-1][j-1] == list1[i+1][j+1] == list1[i-1][j+1] == list1[i+1][j-1] == 'X':
                    count = count + 1
    print(count)

