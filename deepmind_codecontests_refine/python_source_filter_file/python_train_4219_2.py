n = int(input())
s = int(input())

l = sorted([int(input()) for _ in range(n)],reverse = True)
c = 0
while s >= 0:
    s -= l[c]
    c+=1
print (c)