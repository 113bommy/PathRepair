入力 = input()
for i in range(len(入力)-1):
  if 入力[i]==入力[i+1]:
    print(i+1, i+2)
    exit()
  elif i<n-2 and 入力[i]==入力[i+2]:
    print(i+1, i+3)
    exit()
print(-1, -1)