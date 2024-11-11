number, skill = input().split()
number = int(number)
skill = int(skill)
problems = list(map(int, input().split()))
stop_at =0
checked = 0
index = 0
solved = 0
for index in range(len(problems)) :
    if number == checked :
        break
    elif skill >= problems[index] :
        solved=solved+1
        checked = checked+1
    else :
        stop_at = index
        break
for i in range(len(problems)-1, -1, -1) :
    if number == checked :
        break
    elif i == stop_at :
        break
    elif skill >= problems[i]:
        solved = solved + 1
        checked = checked + 1
    else :
        break
print(solved)