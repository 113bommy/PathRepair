a,b = map(int,input().split())
s = str(input())
if s.count('_') == 1 and s[a]== '_':
    print("Yes")
else:
    print("No")