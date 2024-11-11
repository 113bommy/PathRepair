a = input()
i = 0
while i < len(a):
    x = a[i:i+3]
    
    if x == 'ABC' or x == 'ACB' or x == 'BAC' or x == 'BCA' or x == 'CAB' or x == 'CBA':
        print('YES')
        break
    i += 1

if i >= len(a):
    print("NO")