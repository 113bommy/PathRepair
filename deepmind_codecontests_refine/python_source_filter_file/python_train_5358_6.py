h = int(input())
d = int(input())
t = h + d + 1
if h:
    print(1,end=" ")
    for i in range(h,0,-1):
        print(t - i,end = " ")
    for j in range(d,0,-1):
        print(1+j, end = " ")
else:
    for j in range(d,-1,-1):
        print(1+j, end = " ")