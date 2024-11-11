n = int(input())
alph = "abcdefghigklmnopqrstuvwxyz"
for i in range(n):
    setic = set()
    s = input()
    if "".join(sorted(list(s))) in alph: print("Yes")
    else: print("No")