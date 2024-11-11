N = int(input())
num = input()
X = int(num,2)
c = num.count('1')
def A(s):
    if s == 0:
        return 1
    return A(s%(bin(s).count('1'))) + 1
if c==1:
  for i in range(N):
    if num[i] == '1':
      print(0)
    elif i == N-1:
      print(2)
    else:
      print(1)
  exit()
amari1 = X%(c+1)
amari2 = X%(c-1)
for i in range(N):
    if num[i] == '1':
        print(A((amari2-pow(2,N-1-i,c-1))%(c-1)))
    else:
        print(A((amari1+pow(2,N-1-i,c+1))%(c-1)))