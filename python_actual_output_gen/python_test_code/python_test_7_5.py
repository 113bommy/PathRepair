dic = {'A':10**6,'B':10**6,'C':10**6,'AB':10**6,'AC':10**6,'BC':10**6,'ABC':10**6}
n = int(input())

for i in range(n):
  x = input().split(' ')
  key = ''.join(sorted(list(x[1])))
  if int(x[0]) < dic[key]:
    dic[key] = int(x[0])

mins = [
dic['A'] + dic['B'] + dic['C'],
dic['A'] + dic['BC'],
dic['B'] + dic['AC'],
dic['C'] + dic['AB'],
dic['AB'] + dic['AC'],
dic['AB'] + dic['BC'],
dic['AC'] + dic['BC'],
dic['ABC']
]

if min(mins) > 10**5:
  print(-1)
else:
  print(min(mins))
