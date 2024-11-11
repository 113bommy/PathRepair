l1 = [int(x) for x in input().split()]
n,k = l1[0],l1[1]
l2 = input()
ruined=0

if "#"*(k) in l2:
    ruined = 1
if not ruined:
    print("YES")
else:
    print("NO")