n, x, y = list(map(int, input().split()))
s = ""
len_s = 0
a = input()
for i in range(n):
    if len_s == 0:
        s += a[i]
        len_s += 1
    elif a[i] != s[len_s - 1]:
        s += a[i]
        len_s += 1
sm = 0
if x < y:
    if len(s) > 3:
        sm += x * ((len(s) - 2)//2) 
else:
    if len(s) > 3:
        sm += y * ((len(s) - 2)//2) 
sm += y
if len(s) == 3 and s[0] == '0' and s[len(s) - 1] == '0':
    if y < x:
        sm += y
    else:
        sm += x
        
if s == '1':
    sm = 0
print(sm)
