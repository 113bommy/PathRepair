n = int(input())
A = [int(i) for i in input().split()]

B = set()
crown = 0
for a in A:
    if a // 400 >= 8:
        crown += 1
    else:
        B.add(a // 400)

print(max(1, len(B)), min(8, len(B) + crown))