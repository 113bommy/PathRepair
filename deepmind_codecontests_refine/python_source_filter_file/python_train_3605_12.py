n = int( input() )
A = list( map(int, input().split() ) )
B = list( map(int, input().split() ) )

space = []
for i in range(n):
    space.append(B[i])
print(space)

space.sort()

capacity = space[-1] + space[-2]
totalCola = sum(A)
if totalCola <= capacity or n <= 2:
    print("YES")
else:
    print("NO")
