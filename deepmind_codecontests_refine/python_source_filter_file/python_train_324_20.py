n = int(input())
a = list(map(int,input().split()))
odd = []
even = []
for x in a:
    if x%2 == 0:
        even.append(x)
    else:
        odd.append(x)
if abs(len(odd) - len(even))<2:
    print(0)
else:
    if len(odd) > len(even):
        odd.sort()
        s = sum(odd[0:len(odd)-len(even)])
    else:
        even.sort()
        s = sum(odd[0:len(even)-len(odd)])
    print(s)