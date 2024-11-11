num_but, num_lmp = map(int,input().split(" "))
switched = list("-" * num_lmp)
for i in range(num_but):
    print("inputting button {}".format(i))
    inp = input()
    inp = inp.split(" ")
    inp = inp[1:]
    for lamp in inp:
        print("switching on lamp {}".format(lamp))
        switched[int(lamp) - 1] = "+"

for lamp in range(len(switched)):
    if switched[lamp] == "-":
        print("NO")
        break
else:
    print("YES")
