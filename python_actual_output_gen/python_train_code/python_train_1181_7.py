l = [list(map(int,input().split())) for i in range(3)]
ans = 0
for i in l:
  ans += sum(i)
print("Yes" if ans%3==(l[0][0]+l[1][1]+l[2][2]) else "No")
