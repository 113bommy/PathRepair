A=[1]
X=int(input())
for i in range(1,33):
  for j in range(1, 11):
    if i**j<X+1:
      A.append(i**j)
print(max(A))