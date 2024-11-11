str = input()
k = int(input())

occs = [0] * 26

for c in str:
    occs[ord(c) - ord('a')] += 1

arr = [x for x in sorted(occs) if x > 0]

if k > len(str):
    print("impossible")
elif k == len(arr):
    print(0)
else:
    print(k - len(arr))
