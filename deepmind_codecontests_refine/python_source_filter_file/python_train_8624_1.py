n = int(input())
s = input()
l = ['SS','WS','SW','WW']

for i in range(n):
  for j in range(len(l)):
    l[j] += 'SW'[::-1 if s[i]=='o' else 1][l[j][i]==l[j][i+1]]
for i in range(n):
  if l[i][1]==l[i][n+1] and l[i][0]==l[i][n]:
    print(l[i][1:n+1])
    exit()
print(-1)