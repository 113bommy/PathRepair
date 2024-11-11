s = input()
count_4 = 0
count_7 = 0
for x in range(len(s)):
    if s[x] =="4":
        count_4+=1
    elif s[x] == "7":
        count_7+=1
if count_4==0 and count_7 == 0:
    print(-1)
elif count_4 >= count_7:
    print(4)
else:print(7)