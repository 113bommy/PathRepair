for i in range(int(input())):
    n,a,b=map(int,input().split())
    for j in range(n):
        print(chr(ord('a')+i%b),end='')
    print()