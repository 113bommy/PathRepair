#6A
def mos(a, b, c):
    if a + b > c and a + c > b and b + c > a:
        return 7
    if a + b >= c or a + c >= b or b + c >= a:
        return 5
    return 3
s = input()
a = [int(i) for i in s.split()]
d = a[3]
c = a[2]
b = a[1]
a = a[0]
q = []
q.append(mos(a, b, c))
q.append(mos(a, b, d))
q.append(mos(a, c, d))
q.append(mos(b, c, d))
if 7 in q:
    print("TRIANGLE")
else:
    if 5 in q:
        print("SEGMENT")
    else:
        print("IMPOSSIBLE")
    
