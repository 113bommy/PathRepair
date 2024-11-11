a = input()
print(('NO', 'YES')[sum(x in 'AEFHIKLMNTVWXYZ' for x in a) in (0, len(a))])
