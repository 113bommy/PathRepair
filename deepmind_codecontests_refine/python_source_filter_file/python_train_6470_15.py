n = int(input())
string = input()
diff = n-11
no = diff//2
count = 0
j = 0
idx = -1
for i in string:
    if i == '8':
        if count < no:
            count = count + 1
        else:
            idx = j
            break
    j=j+1
if idx == -1:
    print("NO")
else:
    temp = idx-no
    te = diff - no
    if no <= te:
        print("YES")
    else:
        print("NO")
