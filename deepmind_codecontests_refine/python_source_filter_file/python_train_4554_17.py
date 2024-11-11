n = int(input())
marks = list(map(int, input().split()))

marks.sort()
count = 0
i = 0
avg = sum(marks)/n
while avg <= 4.5:
    marks[i] = 5
    i += 1
    count += 1
    avg = sum(marks)/n
print(count)