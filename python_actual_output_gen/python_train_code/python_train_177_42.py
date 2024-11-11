lt = list(map(int,input().split()))
f = lt[0]*lt[1] + 2*lt[3]
s = lt[1]*lt[2] + 2*lt[4]
if f > s:
    print("First")
elif f < s:
    print("Second")
else:
    print("Friendship")