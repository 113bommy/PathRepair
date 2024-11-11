[s, k] = [int(x) for x in input().split()]

numbers = [1]
numbers.append(1)

last = 1
index = 1
while last <= s:
    l_index = index-k
    if l_index >= 0:
        last = last * 2 - numbers[l_index]
    else:
        last *= 2
    # print(last, l_index)
    if last != s:
        numbers.append(last)
    index += 1


numbers.reverse()
numbers.append(0)

# for s in range(0, 100000):
output = []
for i in numbers:
    if i <= s:
        s -= i
        output.append(i)

print(len(output))
print(" ".join([str(x) for x in output]))




