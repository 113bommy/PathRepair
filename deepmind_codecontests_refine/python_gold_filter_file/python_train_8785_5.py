n= int(input())
a = [i for i in range(1, n**2+1)]
ans = [[]]*n
for i in range(0, n**2, n):
    for j in range(n//2):
        # ans[i].append(a[j+i])
        # ans[i].append(a[::-1][i+j])
        print(a[j+i], end = " ")
        print(a[::-1][j+i], end = " ")
    print("")

# print(*ans, sep = " ")


