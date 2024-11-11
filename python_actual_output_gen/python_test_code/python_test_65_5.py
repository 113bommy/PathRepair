x = int(input())
y = input()
if x <= 3:
    print(x)
    quit()

num1 = 0
num0 = 0
for i in y:
    if i == '1':
        num1 = max(num1, num0+1)
    else:
        num0 = max(num0, num1+1)

maxx = max(num1, num0)
if '11' not in y and '00' not in y:
    print(maxx)
    quit()

print(max(maxx+2, x))