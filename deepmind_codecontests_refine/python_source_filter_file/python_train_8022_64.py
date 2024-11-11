a,b = map(int,input().spilit())

if a > b:
    op = '>'
elif a < b:
    op = '<'
else:
    op = '=='
print("a %s b"%op)
