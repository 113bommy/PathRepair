n = int(input())
s = input()

s = "one" * 20 + "zero" * 40  + "one" * 30

zero = s.count('z')
one = s.count('n')

out = "1 " * one + "0 " * zero
print(out)