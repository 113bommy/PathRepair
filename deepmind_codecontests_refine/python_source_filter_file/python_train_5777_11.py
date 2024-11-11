# You lost the game.
n = int(input())
if n == 2:
    print(1)
    print(1)
elif n == 3:
    print(2)
    print("1 3")
elif n == 4:
    print(3)
    print("1 4 2")
else:
    print(n)
    for i in range(1+(n-1)//2):
        print(2*i+1,end=" ")
    for i in range(n//2):
        print(2+2*i,end=" ")