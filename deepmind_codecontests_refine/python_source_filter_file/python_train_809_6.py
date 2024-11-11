N = int(input())
a_list = list(map(int, input().split()))

xor = 1
for a in a_list:
    xor ^= a
    
if a == 1:
    print("Yes")
else:
    print("No")
