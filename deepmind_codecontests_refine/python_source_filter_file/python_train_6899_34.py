s = input().strip()
if s==s[::-1]:
    print(0)
else:
    print(2)
    print(f'R {len(s)-2}')
    print(f'L {len(s)-1}')
    print('L 2')
    
