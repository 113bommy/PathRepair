my_list = {"purple":"power", "green":"Time", "blue":"Space", "orange":"Soul", "yellow":"Mind", "red":"Reality"}

n = int(input())
for i in range(n):
    my_list.pop(input())

print(len(my_list))
for i in my_list:
    print(my_list[i])