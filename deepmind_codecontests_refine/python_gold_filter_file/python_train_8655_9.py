s = input()
a = 0
for idx in s:
    if(idx == 'a'):
        a += 1
 
if(a > len(s)/2):
    print(len(s))
else:
    print(a * 2 - 3 + 2)