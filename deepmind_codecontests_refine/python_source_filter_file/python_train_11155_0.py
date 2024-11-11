import sys
n = int(input())
a = list(map(int,input().split()))
count = 0
for i in range(n-1):
    if a[i+1] != 1 and a[i] != 1:
        print("Infinite")
        sys.exit()
    if a[i] == 1 and a[i+1] == 2:
        count+=3
    if a[i] == 1 and a[i+1] == 3:
        count+=4
    if a[i] == 2 and a[i+1] == 1:
        count+=3
    if a[i] == 3 and a[i+1] == 1:
        count+=4
# for i in range(n-2):
# # will have one overlap
#     if a[i] == 3 and a[i+2] == 2:
#         count-=1
print("Finite")
print(count)