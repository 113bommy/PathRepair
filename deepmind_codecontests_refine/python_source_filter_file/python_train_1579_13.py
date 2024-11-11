n = int(input())
a, b = 0, 0
for i in map(int, input().split()) :
    if(i == 1) : a += 1
    else       : b += 1
if(a == 1 or a == 2) :
  if(b) : 
      print(2, end = ' ')
      b -= 1
if(a % 2) :
    for i in range(a) : print(1, end = ' ')
    for i in range(b) : print(2, end = ' ')
else :
    for i in range(a - 1) : print(1, end = ' ')
    for i in range(b    ) : print(2, end = ' ')
    print(1)
    