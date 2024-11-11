n = int(input(""))
x = 0
for i in range(n):
    a = input("")
    if a == ('++x') or a == ('x++'):
        x = x+1
    elif a == ('--x') or a == ('x--'):
        x = x-1
print(x)
