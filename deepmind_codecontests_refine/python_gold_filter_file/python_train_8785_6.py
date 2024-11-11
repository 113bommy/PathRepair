a = int(input())
for i in range(a):
    for j in range(a//2):
        print(a*j+i+1,end=" ")
    for j in range(a//2):
        print(a**2-a*(a//2-j-1)-i,end=" ")
    print()