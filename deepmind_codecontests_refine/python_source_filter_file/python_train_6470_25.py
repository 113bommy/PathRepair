n = input()
s = input()

str = s[:-11]
c = str.count('8')
l = len(str)

if c >= l //2 :
    print("YES")
else :
    print("NO")