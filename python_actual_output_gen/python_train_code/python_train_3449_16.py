n = input()
even,odd = [],[]
b = list(map(int,input().split()))
for i in b:
    if i%2 == 0:
        even.append(i)
    else:
        odd.append(i)

e,o = len(even),len(odd)
if o%2==0:
    print(e)
else:
    print('1')