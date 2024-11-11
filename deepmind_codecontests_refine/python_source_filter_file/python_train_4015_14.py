n = int(input())
s = input()
count = 0
x = 0
d = ''
for i in range(len(s)):
    if s[i] == 'B' :

            
        count += 1
        if i == n - 1:
            x = x + 1
            d  = d + str(count) + ' '
    elif s[i - 1] == 'B':
        x = x + 1
        d  = d + str(count) + ' '
        count =0
print(x)
if x != 0:
    print(d)

    

