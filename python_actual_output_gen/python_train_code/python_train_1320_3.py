n = int(input())

s = input()

if s == 0:
    print(0)
    
else:
    print('1' + ''.join('0' for _ in range(s.count('0'))))