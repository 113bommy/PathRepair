f_input = int(input())
list = []
x = 0
groups = 1
for n in range(f_input):
    list.append(input())
n=1
while n <(f_input):
    if list[x] == list[x-1]:
        groups =groups
    else:
        groups =groups+1
    x= x+1
    n+=1
print(groups)