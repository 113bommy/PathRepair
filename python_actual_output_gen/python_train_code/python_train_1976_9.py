# You lost the game.
m = int(input())
r = 0
l = 1
n = 0
k = 0
L = []
while n <= m:
    #print("<>")
    k += 1
    l *= k
    #print(l,n,k)
    while l % 10 == 0:
        n += 1
        l = l // 10
    #print(l,n)
    #l = l % 10
    l = int(str(l)[len(str(l))//2:])
    if n == m:
        r += 1
        L += [k]
if r == 0 or r == 5:
    print(r)
    for i in range(r):
        print(L[i],end=" ")
else:
    print(0)
