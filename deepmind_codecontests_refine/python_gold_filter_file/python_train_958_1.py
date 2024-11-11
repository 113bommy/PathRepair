num0 =input()
num1 =input()
count =0
charr =[]
for ch in num0:
    if ch != '0':
        charr.append(int(ch))
        continue
    count+=1
charr.sort()
for i in range(count):
    charr.insert(1,0)
for i in range(len(charr)):
    charr[i] =str(charr[i])
charr =''.join(charr)
#charr =int(charr)
if charr == num1:
    print('OK')
    quit()
print('WRONG_ANSWER')