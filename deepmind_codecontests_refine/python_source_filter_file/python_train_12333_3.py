#! /usr/bin/python
n, max_mark, avg = list(map(int, input().split()))
a, b = [], []
for i in range(n):
    ai, bi = list(map(int, input().split()))
    a.append(ai)
    b.append(bi)

exams = dict(enumerate(zip(a,b)))
marks_needed = int((avg - sum(a)/len(a))*n)
num_essays = 0

if marks_needed > 0:
    for exam in sorted(exams.values(), key = lambda x: x[1]):
        cur_exam_mark, cur_essays_per_mark = exam
        if marks_needed >= max_mark - cur_exam_mark:
            num_essays += cur_essays_per_mark*(max_mark - cur_exam_mark)
            marks_needed -= (max_mark - cur_exam_mark)
        else:
            num_essays += cur_essays_per_mark*marks_needed
            marks_needed = 0

print(num_essays)