y=input()
print(sum(x in 'aeiou' or x in '02468' for x in y))