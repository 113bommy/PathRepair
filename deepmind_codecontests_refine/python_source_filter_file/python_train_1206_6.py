s = input()
s = list(s)
l=['h','e','i','d','i']
j = 0
for i in s:
    if(i==l[j]):
        j = j + 1
        if(j>=4):
            print('YES')
            break
if(j<4):
    print('NO')