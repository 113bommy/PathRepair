binstr = input()
count = 0
l = len(binstr) - 1
while l > 0 and binstr[l] == '0':
    count += 1
    l -= 1
if binstr!= '1':
    count+= (l+1)*2
while l >0 :
    if binstr[l] == '1':
        count-=1
    l-=1

print(count)


