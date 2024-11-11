#ABC64C
n = int(input())
a = list(map(int,input().split()))
b = set()
d = 0
for i in a:
    c = i // 400
    if c < 8:
        b.add(c)
    else:
        d += 1
print(max(len(b),1),min(len(b)+d,8))