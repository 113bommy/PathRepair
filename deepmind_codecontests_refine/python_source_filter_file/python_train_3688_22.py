n = int(input())

Line = input()
Lines = Line.split(' ')

for i in range(len(Lines)):
   Lines[i] = int(Lines[i])

sum = 0

Arg = input()

Args = Arg.split(' ')

for i in range(len(Args)):
    Args[i] = int(Args[i])

for i in range(Args[1] - Args[0]):
    sum += Lines[i]

print(sum)