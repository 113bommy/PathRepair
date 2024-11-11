n=int(input())
if n%2==0:
    x=n/2
    print(int(x))
    for i in range(int(x)):
        print('2',end=" ")
else:
    x=n//2
    print(x)
    for i in range(x):
        print('2',end=" ")
    print('3')
