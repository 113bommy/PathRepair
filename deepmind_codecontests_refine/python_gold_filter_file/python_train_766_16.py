n = int(input())
a = list(map(int, input().split()))

count_neg = 0
count_pos = 0
for el in a:
    if el < 0:
        count_neg += 1
    elif el > 0:
        count_pos += 1

neg, pos, zero = [],[],[]
j,k = 0,0
if count_pos == 0:
    for i in range(n):
        if a[i] < 0 and j < 2:
            pos.append(a[i])
            count_neg -= 1
            j += 1
        elif a[i] < 0 and k < 1:
            neg.append(a[i])
            count_neg -= 1
            k += 1
        else:
            zero.append(a[i])
else:
    for i in range(n):
        if a[i] > 0:
            pos.append(a[i])
        elif a[i] < 0 and k < 1:
            neg.append(a[i])
            count_neg -= 1
            k += 1
        else:
            zero.append(a[i])
            
print (len(neg), *neg)
print (len(pos), *pos)
print (len(zero), *zero)