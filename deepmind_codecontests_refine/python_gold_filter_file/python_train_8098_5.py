n=int(input())
cnt =0
for i in range(1,1+n):
  if len(str(i)) % 2 == 1:
    cnt += 1
print(cnt)