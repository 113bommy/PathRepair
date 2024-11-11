import sys

input = sys.stdin.readline

for _ in range(int(input())):
    s = input().strip() # remove non-adjacent values to make sorted
    if s.find("11") < s.rfind("00") and s.find("11") != -1 and s.rfind("00") != -1:
        print("NO")
    else:
        print("YES")
