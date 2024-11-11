a=input()
if '4' not in a and '7' not in a:
    exit(print(-1))
else:
    print([7,4][a.count('4')>a.count('7')])