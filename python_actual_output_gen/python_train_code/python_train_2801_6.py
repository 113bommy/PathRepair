x, y, a, b = [int(i) for i in input().split()]
"""
if (x - a) < b:
    print(0)
else:
"""
arr = []
for i in range(1, x-a+1):
    a_wins = a+i
    if a_wins > b:
        for j in range(i+1):
            b_wins = b+j
            if b_wins <= y and a_wins > b_wins:
                arr += [[a_wins, b_wins]]

print(len(arr))
for vals in arr:
    print(" ".join([str(i) for i in vals]))
