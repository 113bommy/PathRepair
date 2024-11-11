s = input()
a, b = [0], [0]
a_count, b_count = 0, 0
for x in s:
    if x == 'a':
        a_count += 1
    else:
        b_count += 1
    a.append(a_count)
    b.append(b_count)

#print(a)
#print(b)
best = 0
for i in range(1,len(a)):
    for j in range(i, len(a)):
        print(a[i],b[j],b[i],best)
        best = max(best, a[i] + (a_count-a[j]) + (b[j]-b[i]))
        print(best)
print(best)

