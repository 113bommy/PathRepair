n_k = input()
lst_1 = n_k.split(" ")
a = input()
lst_2 = a.split(" ")
place = int(lst_1[1])
value_to_beat = int(lst_2[int(lst_1[1]) - 1])
count = 0
if value_to_beat > 0:
    count = len(lst_2[:place - 1])
else:
    for i in lst_2[:place - 1]:
        if int(i) > 0:
            count += 1
        else:
            break
for i in lst_2[place - 1:]:
    if int(i) > 0 and int(i) == value_to_beat:
        count += 1
print(count)