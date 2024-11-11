n = int(input())
c = 0
while n:
    c+=n%10
    n//=2
print(c)