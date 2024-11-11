n = int(input())
arr = input()
s = list(set([i for i in arr.split()]))
if len(s) == 1:
    print("NO")
else:
    s.sort()
    print(s[1])
