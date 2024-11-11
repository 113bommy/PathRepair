n = int(input())
li = input().split(' ')

prev_one = -1
num_of_ways = 1

i = 0
while i < len(li):
    if li[i] == '1':
        if prev_one != -1 and i - prev_one > 1:
            num_of_ways *= i - prev_one
            prev_one = i
        else:
            prev_one = i
    i += 1

if num_of_ways == 0 and prev_one != -1:
    print(1)
else:
    print(num_of_ways)