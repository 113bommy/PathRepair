num = int(input())
x = [int(i) for i in input().split()]
odd, even = [], []
for i in x:
    if i % 2 == 0:
        even.append(i)
    else:
        odd.append(i)
even = sorted(even)
odd = sorted(odd)
diff = len(even) - len(odd)
if diff > 1:
    print(sum(even[:-(diff-1)]))
elif diff < -1:
    print(sum(odd[:-(diff-1)]))
else:
    print(0)