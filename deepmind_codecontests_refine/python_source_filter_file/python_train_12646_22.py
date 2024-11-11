def check(x):
    y = {}
    for i in range(97, 123):
        if x.rfind(chr(i)) == False:
            return 'NO'
    return 'YES'

n = input()
x = input()
x = x.lower()
print(check(x))