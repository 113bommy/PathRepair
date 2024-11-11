
for i in range(int(input())):
    a, b = sorted(list(map(int, input().split())))
    c, d = sorted(list(map(int, input().split())))
 
    if a + c == d or d == b:
      print("Yes")
    else:
      print("No")