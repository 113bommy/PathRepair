x = input()
s = []
count = 0
while count<len(s):
    if len(s) != 0 and x[count] == s[-1]:
        s.pop()
        count+=1
        continue
    s.append(x[count])
    count += 1
if s == []:
    print("Yes")
else:
    print("No")