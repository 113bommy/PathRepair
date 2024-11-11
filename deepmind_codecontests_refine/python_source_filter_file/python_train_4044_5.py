t=[0,1]
for i in range(2,90):
  t.append(t[i-1]+t[i-2])
print(t(int(input())