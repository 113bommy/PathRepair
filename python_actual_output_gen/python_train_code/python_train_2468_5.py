n = int(input())
curr_direct = "North"
curr_value = 0
for i in range(n):
    value, direct = input().split()
    if curr_direct == "North" and direct != "South" and curr_value == 0:
        print("NO")
        break
    if curr_direct == "South" and direct != "North" and curr_value == 20000:
        print("NO")
        break
    if direct == "South":
        curr_value += int(value)
    if direct == "North":
        curr_value -= int(value)
    curr_direct = direct
    if curr_value < 0 or curr_value > 20:
        print("NO")
        break
else:
    if curr_value == 0:
        print("YES")
    else:
        print("NO")
