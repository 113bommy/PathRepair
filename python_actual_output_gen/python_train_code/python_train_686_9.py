n = int(input())
s = input()
for o in s:
    print(chr((ord(o)+n-ord('A'))%27+ord('A')),end="")
print()