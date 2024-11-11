a = int(input())
b = int(input())
if a > b or a == b or len(str(b)) > 7:
    print(b)
else:
    print(int(b % (2 ** a)))