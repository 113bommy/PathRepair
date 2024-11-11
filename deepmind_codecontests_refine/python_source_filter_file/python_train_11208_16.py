num = int(input())
lst = str(input())
lst = [str(x) for x in str(lst)]

matches = []
matches_arr = []

for item in lst:
  if item == 'x':
    matches_arr.append('x')
  else:
    if len(matches_arr) > 2:
      matches.append(matches_arr)
      matches_arr = []

if len(matches_arr) > 2:
   matches.append(matches_arr)
   matches_arr = []

remove_count = 0
for item in matches:
  if len(item) == 3:
    remove_count +=1
  elif len(item) > 3:
    remove_count += len(item) - 2

print(remove_count)