import re

true_answers = []
to_check = []

a = re.sub(r"[-_;]", "", input().lower())
b = re.sub(r"[-_;]", "", input().lower())
c = re.sub(r"[-_;]", "", input().lower())

true_answers.append(a+b+c)
true_answers.append(a+c+b)
true_answers.append(b+c+a)
true_answers.append(b+a+c)
true_answers.append(c+a+b)
true_answers.append(c+b+a)

n = int(input())

for i in range(n):
    true_answers.append(re.sub(r"[-_;]", "", input().lower()))

for i in to_check:
    if i in true_answers:
        print("ACC")
    else:
        print("WA")
