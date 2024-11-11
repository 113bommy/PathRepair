n = int(input())
s = list(input())

zero = len(list(filter(lambda x: x == "0",s)))
one = len(list(filter(lambda x: x == "1",s)))
if zero != one:
    print(1)
    print(s)
else:
    a = s.pop(0)
    print(2)
    print(a,"".join(s))