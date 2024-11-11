n = int(input())
i = 0
k = 0
g = 0
while i < n :
    b = input().split(" ")
    c = int(b[0])
    d = int(b[1])
    if c > d :
        k = k + 1
    if c < d :
        g = g + 1
    i = i + 1
if k > g :
    print("Mishka")
if k == g :
    print("Chris")
if k == g :
    print("Friendship is magic!^^")
