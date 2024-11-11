n, w = input().split()
string = input()

ints = map(int, string.split())
alist = []
for num in ints:
    alist.append(num)

alist.sort()

if (alist[0] * 2 <= alist[int(n)]):
    g = alist[0]
else:
    g = alist[int(n)]/2

ans = 3.0 * float(n) * g
if ans <= float(w):
    print(ans)
else:
    print(0)
    
