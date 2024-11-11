for i in range(int(input())):
    a, b = sorted(list(map(int, input().split())))
    c, d = sorted(list(map(int, input().split())))
 
    if a + c == d and b == d:
      print("Yes")
    else:
      print("No")