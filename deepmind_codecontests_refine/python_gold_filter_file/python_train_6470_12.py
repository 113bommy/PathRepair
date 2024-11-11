n = int(input())
S = input()
X = (n - 11) 
heh = set() 
heh.add('8')
if S[:X+1].count('8') > X // 2:
    print('YES')
else:
    print('NO')