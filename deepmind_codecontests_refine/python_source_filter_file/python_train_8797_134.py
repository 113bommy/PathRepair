number= int(input())
one = 0
two = 0
three = 0
four = 0
five = number//5
remainder = number % 5
if remainder% 4 == 0:
    four = remainder // 4
elif remainder % 3 == 0:
    three = remainder // 3
elif remainder % 2 == 0:
    two = remainder // 2
elif remainder % 1 == 0:
    one = remainder /1
print(one+two+three+four+five)

