dic = {'A':0, 'B':0, 'C':0}

for _ in range(3):
    a = input()
    if a[1] == ">":
        dic[a[0]] += 1
    else:
        dic[a[2]] += 1

ndic = sorted(dic.items(), key=lambda x:x[1], reverse=False)

if not ndic[0][0] == 0 or not ndic[1][1] == 1 or not ndic[2][1] == 2:
    print("Impossible")
else:
    print(f"{ndic[0][0]}{ndic[1][0]}{ndic[2][0]}")
