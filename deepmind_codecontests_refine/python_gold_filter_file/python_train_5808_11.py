n, a, b, c = map(int, input().split())
column = [a, b, c]
dict_convert = {"A": 0, "B": 1, "C": 2}
reverse_convert = {0: "A", 1: "B", 2: "C"}
s = list()
for _ in range(n):
  pair = tuple(dict_convert[val] for val in tuple(input()))
  s.append(pair)
choices = list()
def generate_play():
  for i in range(n):
    if column[s[i][0]] == 0 and column[s[i][1]] == 0:
      return "No"
    elif column[s[i][0]] == 1 and column[s[i][1]] == 1 and i<n-1:
      other_index = next(x for x in range(3) if x not in (s[i][0], s[i][1]))
      if s[i+1] == (other_index, s[i][0]) or s[i+1] == (s[i][0], other_index):
        choice = s[i][0]
        column[s[i][1]] -= 1
        column[s[i][0]] += 1
      else:
        choice = s[i][1]
        column[s[i][1]] += 1
        column[s[i][0]] -= 1
      choices.append(choice)
    else:
      if column[s[i][0]] >= column[s[i][1]]:
        choice = s[i][1]
        column[s[i][1]] += 1
        column[s[i][0]] -= 1
      else:
        choice = s[i][0]
        column[s[i][1]] -= 1
        column[s[i][0]] += 1
      choices.append(choice)
  return "Yes"
ans = generate_play()
print(ans)
if ans == "Yes":
  [print(reverse_convert[val]) for val in choices]