n , x , y = map(int , input().split())
s = input()
c = 0
for i in range(len(s)-1):
    if s[i] == '0' and s[i+1] == '1' :
        c += 1
if s[len(s)-1] == '0' :
    c += 1
if c == 0 :
    print(0)
else :
    print((c-1)*min(x , y) + y )