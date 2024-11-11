input = input()
input = input.rstrip()
quasi = True
for i in range(len(input)):
    j = len(input) - 1 - i
    if input[i] != input[j]:
        quasi = False
        print("NO")
        break
if quasi:
    print("YES")
