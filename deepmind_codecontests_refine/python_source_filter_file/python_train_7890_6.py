input()
s = list(input())
print("".join(("*" if x != y else x for x in s[int(input())] for y in s )))