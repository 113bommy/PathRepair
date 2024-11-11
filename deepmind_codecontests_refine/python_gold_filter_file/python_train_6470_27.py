n = input()
s = input()

str = s[:-10]
c = str.count('8')
l = len(str)

if c > l // 2 :
    print("YES")
else :
    print("NO")