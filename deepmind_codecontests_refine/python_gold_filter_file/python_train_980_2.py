a = input()
b = input()

score = 0

for i in range(0, len(a), 2):
    first = a[i:i+2]
    second = b[i:i+2]
    if first == second:
        continue
    elif first == "[]":
        if second == "8<":
            score = score - 1
        else:
            score = score + 1
    elif first == "()":
        if second == "[]":
            score = score - 1
        else:
            score = score + 1
    else:
        if second == "()":
            score = score - 1
        else:
            score = score + 1

if score == 0:
    print("TIE")
elif score < 0:
    print("TEAM 2 WINS")
else:
    print("TEAM 1 WINS")
