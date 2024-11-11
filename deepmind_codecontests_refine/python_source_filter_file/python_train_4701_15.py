import math

l = int(input())
s = input()
ans = []

if l%2==1:
    print(":(")
    exit()

#exclusive
left = right = l//2
unused_left = left
unused_right = right
gap = 0

for i,v in enumerate(s):
    if v=="(":
        unused_left -=1
    elif v==")":
        unused_right -=1


if unused_left<0 or unused_right<0:
    print(":(")
    exit()


for i,v in enumerate(s):
    if v=="(":
        ans.append(v)
        gap += 1
    elif v==")":
        ans.append(v)
        gap -= 1
    else:
        if unused_left>0:
            ans.append("(")
            unused_left -= 1
            gap += 1
        else:
            ans.append(")")
            gap -= 1
            #unused_right -= 1

    if i<l-1 and gap==0:
        print(":(")
        exit()

for v in ans:
    print(v, end="")
