n = int(input())
if n%2 == 1:
    print(0)
else:
    print(1 << n//2)