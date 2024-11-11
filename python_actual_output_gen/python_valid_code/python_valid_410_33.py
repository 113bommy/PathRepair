from sys import stdin as input,stdout as print

layers = int(input.readline())
result = 'I Hate'
flag = True

while layers !=1:

    if flag:
        result += ' that I love'
        flag = False
        layers -= 1

    else:
        result += ' that I hate'
        flag = True
        layers -= 1

print.write(result + ' it')

#3
