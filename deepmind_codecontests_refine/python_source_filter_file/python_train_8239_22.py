n = int(input())
a = [int(item) for item in input().split()]
total = sum(a)
alice = a[0]
others = []
 
for i, item in enumerate(a[1:]):
    others.append((item, i+2))
 
others.sort()
alice_party = 0
ans = []
for num, index in others:
    if alice_party > total / 2:
        break
    if alice < num * 2:
        print(0)
        exit()
    else:
        alice_party += num
        ans.append(index)
ans.append(1)
print(len(ans))
print(" ".join([str(item) for item in ans]))