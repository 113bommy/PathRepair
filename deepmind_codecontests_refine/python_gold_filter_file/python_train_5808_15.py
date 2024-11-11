N,A,B,C = map(int,input().split())
data = {
  "A":A,
  "B":B,
  "C":C
}
select = []
S = list(input() for _ in range(N))
for i in range(N):
  s = S[i]
  if data[s[0]] == data[s[1]] ==0:
    print("No")
    exit(0)
  elif data[s[0]] > data[s[1]]:
    data[s[0]] -= 1
    data[s[1]] += 1
    select.append(s[1])
  elif data[s[0]] < data[s[1]]:
    data[s[0]] += 1
    data[s[1]] -= 1
    select.append(s[0])
  elif i == N-1:
    select.append(s[0])
  elif s[0] in S[i+1]:
    data[s[0]] += 1
    data[s[1]] -= 1
    select.append(s[0])
  else:
    data[s[0]] -= 1
    data[s[1]] += 1
    select.append(s[1])
print("Yes")
for i in select:
  print(i)