n = int(input())
cases = []
for i in range(n):
    cases.append(list(map(int, input().split())))
 
for i in cases:
    x = i[0]
    y = i[1]
    a = i[2]
    b = i[3]
    one = y*a
    two = y*(x-a-1)
    three = x*(y-b-1)
    four = x*b
    foo = [one, two, three, four]
    print(max(foo))