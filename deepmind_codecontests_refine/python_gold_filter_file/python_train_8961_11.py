N = int(input())

students = input().split(' ')

for i in range(N):
    students[i] = int(students[i])

stack = []
output = []

for i in range(N):
    stack = []
    j = i
    stack.append(i+1)
    while(1):
        temp = students[j]
        if temp not in stack:
            stack.append(temp)
            j = temp-1
        else:
            output.append(temp)
            break


print(*output)