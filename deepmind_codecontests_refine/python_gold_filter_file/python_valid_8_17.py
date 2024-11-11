for i in range (int(input())):
  number = int(input())
  if number%3 == 0:
    print(number//3, number//3)
  elif number%3 == 1:
    print(number//3 +1, number//3)
  else:
    print(number//3, number//3 +1)