import sys
f = sys.stdin
#f = open("input.txt", "r")
n = int(f.readline())
t = [int(i) for i in f.readline().split()]
if n>1:
    if sorted(t)[0] == sorted(t)[1]:
        print("Still Rozdil")
    else:
        print(t.index(sorted(t)[0])+1)
else:
    print(t[0])