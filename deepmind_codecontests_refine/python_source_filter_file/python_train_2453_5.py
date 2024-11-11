first_day = str(input())
sec_day = str(input())
days_list = ["monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"]
a = days_list.index(first_day)
b = days_list.index(sec_day)
s = b-a
if s in [0,2,3,-2,-3]:
    print('Yes')
else:
    print('No')
