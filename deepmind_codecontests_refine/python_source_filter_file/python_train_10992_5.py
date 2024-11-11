s = input()
l = [x for x in range(len(s)) if s[x] == 'a']
# print(l)
i, step = 0, 0
while l:
    step += (len(s) + step - l.pop() - 1 - i) % (10 ** 9 + 7)
    i += 1


print(step)