# Press Umschalt+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

n = int(input())
inp = []
for i in range(n):
    inp.append(input())

sort = sorted(inp, key=len)

for i in range(n - 1):
    if sort[i] not in sort[i + 1]:
        print("NO")
        quit()

print("Yes")
for element in sort:
    print(element)
