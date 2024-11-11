x = int(input())

a = 0
if x % 4 == 1:
    print(a,"A")
if x % 4 == 3:
    a += 2
    print(a,"B")
if x % 4 == 2:
    a += 1
    print(a,"B")
if x % 4 == 0:
    a += 1
    print(a,"A")
