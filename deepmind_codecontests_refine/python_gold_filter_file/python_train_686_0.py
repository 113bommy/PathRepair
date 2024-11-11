n1, n2 = map(int, input().split())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))
min = int(str(l1[0]) + str(l2[0]))

for i in range(n1):
    for j in range(n2):
        if str(l1[i]) == str(l2[j]) and l1[i] < min:
            min = l1[i]
        elif int(str(l1[i]) + str(l2[j])) < min:
            min = int(str(l1[i]) + str(l2[j]))

for i in range(n2):
    for j in range(n1):
        if int(str(l2[i]) + str(l1[j])) < min:
            min = int(str(l2[i]) + str(l1[j]))
print(min)
