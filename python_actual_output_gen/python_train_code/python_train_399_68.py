n = int(input())
a = [int(i)//400 for i in input().split()]
s = set()
f = 0
for i in a:
    if i>=8:
        f += 1
    else:
        s.add(i)
mn = len(s)
if len(s)==0: mn += f>0
mx = min(8, len(s)+f)
print(mn, mx)