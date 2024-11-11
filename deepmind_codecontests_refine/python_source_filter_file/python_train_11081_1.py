



a = list(input())
a.pop(0)
a.pop(0)
b = list(input())
b.pop(0)
b.pop(0)
c = list(input())
c.pop(0)
c.pop(0)
d = list(input())
d.pop(0)
d.pop(0)


list1 = [b,c,d]


list2 = [a,c,d]


list3 = [a,b,c]

list4  = [a,b,d]


empty = []

temp = 1
count = 0
count1 = 0
count2 = 0
for i in range(len(list1)):

    if len(a) >= len(list1[i])*2 :
        count1+=1
        continue
    if len(a)<=len(list1[i])/2:
        count2+=1
        continue

    else:
        count+=1
        temp = 0
        break

if temp == 1 and (count1 == 3 or count2 == 3):

    empty.append('A')




count1 = 0
count2 = 0

temp = 1
for i in range(len(list2)):

      if len(b) >= len(list2[i])*2 :
        count1+=1
        continue
      if len(b)<=len(list2[i])/2 :
          count2+=1
          continue
      else:
         count+=1
         temp = 0
         break


if temp == 1 and (count1 == 3 or count2 == 3):

        empty.append('B')

count1 = 0
count2 = 0
temp = 1
for i in range(len(list3)):



    if len(d) >= len(list3[i])*2 :
        count1+=1
        continue
    elif len(d)<=len(list3[i])/2:
       count2+=1
       continue



    else:
            count+=1
            temp = 0
            break

if temp == 1 and (count1 == 3 or count2 == 3):
    empty.append('D')


count1 = 0
count2 = 0
temp = 1
for i in range(len(list4)):

    if len(c) >= len(list4[i])*2 :
        count1+=1
        continue
    if len(a)<=len(list4[i])/2:
        count2+=1
        continue



    else:
            count+=1
            temp = 0
            break

if temp == 1 and (count1==3 or count2 == 3):
        empty.append('D')

if len(empty) > 1 or len(empty) == 0:
    print('C')

else:
    print(empty[0])

