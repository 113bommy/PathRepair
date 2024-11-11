a = int(input().strip())
for i in range(1, 11):
    floor = str(a + i)
    if '8' in floor:
        print(i)
        break