n = int(input())
count = 0
flag = True
if (n % 4 == 0 and n % 100 != 0) or n % 400 == 0 :
  flag = False
while True:
    n += 1
    if n % 400 == 0:
        count += 2
    elif n % 4 == 0 and n % 100 != 0:
      count += 2
    else:
        count += 1
    #print(count)
    if count % 7 == 0:
        if flag == False and ((n % 4 == 0 and n % 100 != 0) or n % 400 == 0):
          print(n)
          break
        elif flag == True and ((n % 4 != 0 or n % 100 == 0) and n % 400 != 0):
          print(n)
          break
        else:
          continue