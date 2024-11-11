n = int(input())
a0 = 0
a1 = 0
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
for a in A:
    if a >= a0:
        a1 = a0
        a0 = a
    elif a >= a1:
        a1 = a
if a1+a0>=sum(B):
    print ("YES")
else:
    print("NO")
