n=int(input())
s=input()
if(s.count('0')!=s.count('1')):
    print('1')
    print(s)
else:
    print('2')
    print(s[:n//2],end=" ")
    print(s[n//2:])