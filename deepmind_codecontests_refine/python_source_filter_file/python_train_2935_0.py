l = ['W','B']
n = int(input())
for i in range(n):
    for j in range(n):
        print(l[(i+j)%2],end=" ")
    print()