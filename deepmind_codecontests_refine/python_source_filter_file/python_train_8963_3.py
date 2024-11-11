import sys
input = sys.stdin.readline
q = int(input())
right = []
right_s = set()
l_right = 0
left = []
left_s = set()
l_left = 0
l = 0
for i in range(q):
    char, n = input().split()
    numb = int(n)
    if char == 'L':
        left.append(numb)
        left_s.add(numb)
        l_left += 1
    elif char == 'R':
        right.append(numb)
        right_s.add(numb)
        l_right += 1
    else:
        if numb in right_s:
            z = right.index(numb)
            if l_left != 0:
                print(min(l_right - z - 1, l_left))
            else:
                print(min(l_right - z - 1, z))
        else:
            z = left.index(numb)
            if l_right != 0:
                print(min(l_left - z - 1, l_right))
            else:
                print(min(l_left - z - 1, z))