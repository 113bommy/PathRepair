n = int(input())
count = 0
othercount = 0
for i in range(n):
    m, c = input().split()
    m = int(m)
    c = int(c)
    if m > c:
        count += 1
    else:
        othercount += 1
if count > othercount:
    print("Mishka")
elif count < othercount:
    print("Chris")
elif count == othercount:
    print("Friendship is magic!^^")