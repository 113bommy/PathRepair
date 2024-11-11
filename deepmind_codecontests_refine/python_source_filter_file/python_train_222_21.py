n=int(input('Length:'))
s=input()
if n==1:
    print(n)
    print(s)
elif s.count('0')!=s.count('1'):
    print('1')
    print(s)
else:
    print('2')
    print(s[0],s[1:])
    