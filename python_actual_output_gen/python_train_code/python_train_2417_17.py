num = int(input())
lucky = False
ar = (4, 7, 44, 47, 74, 77, 444, 447, 474, 744, 774, 777)

for n in ar:
    if num % n == 0:
        lucky = True
        break

if lucky:
    print("YES")
else:
    print("NO")

