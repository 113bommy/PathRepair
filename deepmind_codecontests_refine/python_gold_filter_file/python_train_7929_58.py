a = int(input())
A = list(map(int, input().split()))
b = int(input())
B = list(map(int, input().split()))
h,u=0,0
for i in A:
    for j in B:
        if i+j not in A and i+j not in B:
            h,u=i,j
print(h,u)