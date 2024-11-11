import sys

def make_gen(str):
    arr = str.split(" ")
    for item in arr:
        yield int(item)


n = int(input())

class_a = [0] * 5
class_b = [0] * 5

s = input()
s = make_gen(s)

for i in range(0, n):
    x = next(s)
    class_a[x - 1] += 1

s = input()
s = make_gen(s)
for i in range(0, n):
    x = next(s)
    class_b[x - 1] += 1

change1 = 0
change2 = 0

for i in range(0,5):
    if(class_a[i]+class_b[i]%2 == 1):
        print(-1)
        sys.exit()
    med = (class_a[i]+class_b[i]) // 2
    change1 += abs(class_a[i]-med)
    change2 += abs(class_a[i]-med)
if(change1==change2):
    print(change1//2)
else:
    print(-1)