a,b=map(int,input().split())
print("100 100")
for i in range(50):
  if i%2:
    print('#'*100)
  else:
    for j in range(50):
      if a>1:
        a-=1
        print('.#',end='')
      else:
        print('##',end='')
    print()

for i in range(50):
  if i%2:
    print('.'*100)
  else:
    for j in range(50):
      if b>1:
        b-=1
        print('.#',end='')
      else:
        print('..',end='')
    print()