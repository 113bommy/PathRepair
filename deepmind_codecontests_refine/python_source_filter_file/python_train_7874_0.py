flag = False
for i in range(10):
    print(i)
    j = input().strip()
    if j == 'cool' or j == 'not bad' or j == 'great!' or j == "don't think so" or j == "don't touch me!":
        flag = True
        break
    if j != 'no':
        break
if flag:
    print('normal')
else:
    print('grumpy')