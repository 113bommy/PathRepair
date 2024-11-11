
n=3
pairs = [[2,5,7],[5,1,7],[7,7,4]]

n = int(input())
pairs = [[None for _ in range(n)] for _ in range(n)]
for i in range(n):
  pairs[i] = [int(x) for x in input().split(' ')]
salaries = [pairs[i][i] for i in range(n)]
report_sets = [[i] for i in range(n)]
done = [False for _ in range(n)]
boss = None
relationships = []
report_sets_to_indices = {}

while True:
  index = None
  for i, d in enumerate(done):
    if not d:
      index = i
      break
  if index is None:
    break
  done[index] = True
  reports = report_sets[index]
  salary = salaries[index]
  direct_manager_salary = min(
      [x for x in pairs[reports[0]] if x > salary])
  direct_manager_reports = tuple(
      x for x in range(n) if pairs[reports[0]][x] <= direct_manager_salary)
  if direct_manager_reports not in report_sets_to_indices:
    salaries.append(direct_manager_salary)
    report_sets.append(direct_manager_reports)
    report_sets_to_indices[direct_manager_reports] = len(salaries)
    if len(direct_manager_reports) == n:
      boss = len(salaries)
      done.append(True)
    else:
      done.append(False)
  relationships.append((index+1, report_sets_to_indices[direct_manager_reports]))
print(len(salaries))
print(' '.join([str(x) for x in salaries]))
print(boss)
for r in relationships:
  print('{} {}'.format(r[0], r[1]))

