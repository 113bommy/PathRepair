a = int(input())
i = 1
h = 0
g = 0
while i<=a:
    b,c = map(int,input().split())
    if b>c:
        h = h+1
    elif b<c:
        g = g+1
    i = i+1
if h > g:
    print("Mishka")
elif h < g:
    print("Chris")
else:
    print("Frendship is magik")
