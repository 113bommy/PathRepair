n = int(input())
m = n//4
for i in range(0,m):
    print("abcd", end = "")
if n % 4 == 1:
    print("a")
if n % 4 == 2:
    print("ab")
if n % 4 == 3:
    print("abc")
if n % 4 == 0:
    print()
