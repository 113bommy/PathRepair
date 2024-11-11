# maa chudaaye duniya
left, right = map(int, input().split())
found = False
for num in range(left + 1, right):
    w = map(str, str(num))
    if len(set(w)) == len(str(num)):
        print(num)
        found = True
        break
if not found:
    print(-1)