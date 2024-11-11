n = int(input())
l = list((map(int, (input().split()))))
l.reverse()
l1 = [l[0]//2]
l2 = [l[0]-l1[0]]
for i in range(1, n//2):
    if l[i] < l[i-1]:
        l1.append(l1[i-1]-1)
        l2.append(l[i]-l1[i])
    else:
        l1.append(l1[i-1])
        l2.append(l[i]-l1[i])
l1.reverse()
l1 = map(str, l1)
l2 = map(str, l2)
print(" ".join(l1) + " " + " ".join(l2))
