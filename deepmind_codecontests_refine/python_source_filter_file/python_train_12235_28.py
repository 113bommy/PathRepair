n=int(input())
if(n>3):
    print(4*(6*(4**(n-3))+9*(4**(n-4))))
else:
    print(4*(6*(4**(n-3))))