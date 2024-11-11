a = int(input())
b = int(input())
if a > b or a == b or  len(str(a)) > 6:
    print(b)
else:
    print(int(b % (2 ** a)))