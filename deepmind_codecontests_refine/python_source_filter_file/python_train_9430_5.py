line1 = input()
line2= input()
line3=input()
count1=0
count2=0
count3=0
for i in line1:
    if i in {'a', 'e', 'i', 'o', 'u'}:
      count1+=1

for i in line2:
    if i in {'a', 'e', 'i', 'o', 'u'}:
      count2+=1

for i in line2:
    if i in {'a', 'e', 'i', 'o', 'u'}:
      count2+=1

if count1==5 and count2==7 and count3==5:
    print("YES")
else:
    print("NO")
