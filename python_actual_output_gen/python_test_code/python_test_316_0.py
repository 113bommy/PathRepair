l = tuple(input())
sum = 0

for i in range(len(l)):
    if l[i] == 'a' or l[i] == 'i' or l[i] == 'u' or l[i] == 'e' or l[i] == 'o':
        sum += 1
    if l[i] == '0' or l[i] == '2' or l[i] == '4' or l[i] == '6' or l[i] == '8':
        sum += 1

print(sum)
