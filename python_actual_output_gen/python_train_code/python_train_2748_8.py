S = input()
K = int(input())

for i in S[:K+1]:
    if i != "1":
        print(i)
        break
else:
    print(i)