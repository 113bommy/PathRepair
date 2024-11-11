N,P=map(int,input().split(' '))
A=list(map(int,input().split(' ')))
for i in A:
    if i%2 != 0:
        print(2**(N-1))
        exit()
if P ==0:
    print(2**N)
else:
    print(0)