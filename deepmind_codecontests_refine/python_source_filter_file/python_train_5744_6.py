a = input('')
for i in range(int(a),int(a)+5):
    s = []
    for j in range(len(str(i))):
        s.append(int(str(i)[j]))
    if sum(s)%4 == 0:
        print(i)
        break