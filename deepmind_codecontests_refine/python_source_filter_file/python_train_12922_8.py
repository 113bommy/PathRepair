#529_B

l = int(input())

ln = [int(i) for i in input().split(" ")]

mn = 10000000
mn2 = 10000000
omn = mn

mx = 0
mx2 = 0
omx = mx

for i in range(0, len(ln)):
    if ln[i] < mn:
        mn2 = mn
        mn = ln[i]
    elif ln[i] < mn2:
        mn2 = ln[i]
    if ln[i] > mx:
        mx2 = mx
        mx = ln[i]
    elif ln[i] < mx2:
        mx2 = ln[i]

if len(ln) == 2:
    print(0)
elif mx2 - mn < mx - mn2:
    print(mx2 - mn)
else:
    print(mx - mn2)
    
