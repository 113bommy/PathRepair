input = input()
input = input.rstrip("0")
quasi = True
for i in range(len(input)):
    j = len(input) - 1 - i
    if input[i] != input[j]:
        quasi = False
        print("NO")
        break
if quasi:
    print("YES")
