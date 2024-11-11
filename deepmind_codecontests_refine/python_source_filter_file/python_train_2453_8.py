one_day = str(input())
another_day = str(input())
first_variant = ""
second_variant = ""
third_variant = ""
if one_day == "monday":
    one_day = 1
if one_day == "tuesday":
    one_day = 2   
if one_day == "wednesday":
    one_day = 3   
if one_day == "thursday":
    one_day = 4
if one_day == "friday":
    one_day = 5
if one_day == "saturday":
    one_day = 6
if one_day == "sunday":
    one_day = 7  

result = one_day + 3
if result > 7:
    result -= 7
another_result = one_day + 2
if another_result > 7:
    another_result -= 7
third_result = one_day 

if result == 1: 
    first_variant = "monday"
elif result == 2:
    first_variant = "tuesday"
elif result == 3:
    first_variant = "wednesday"
elif result == 4:
    first_variant = "thursday"
elif result == 5 :
    first_variant = "friday"
elif result == 6:
     first_variant = "saturday"
elif result == 7:
     first_variant = "sunday"

if another_result == 1: 
    second_variant = "monday"
elif another_result == 2:
    second_variantt = "tuesday"
elif another_result == 3:
    second_variant = "wednesday"
elif another_result == 4:
    second_variant = "thursday"
elif another_result == 5 :
    second_variant = "friday"
elif another_result == 6:
     second_variant = "saturday"
elif another_result == 7:
     second_variant = "sunday"

if third_result == 1: 
    third_variant = "monday"
elif third_result == 2:
    third_variant = "tuesday"
elif third_result == 3:
    third_variant = "wednesday"
elif third_result == 4:
    third_variant = "thursday"
elif third_result == 5 :
    third_variant = "friday"
elif third_result == 6:
     third_variant = "saturday"
elif third_result == 7:
     third_variant = "sunday"


if first_variant == another_day or second_variant == another_day or third_variant == another_day:
    print("Yes")
else:
    print("NO")



        