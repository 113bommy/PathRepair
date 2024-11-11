n=int(input())

if n&1:
    print(0)
else:
    print(2*(2**n//2))