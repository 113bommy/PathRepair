from collections import Counter
N = int(input())
List = []
for i in range(N):
    S = input()
    slash = S.split("/")
    c = int(slash[1])
    plus = slash[0].split("+")
    a = int(plus[0][1:])
    b = int(plus[1][:-1])
    x = (a+b)/c
    List.append(x)
Dict = Counter(List)
Ans = []

for i in List:
    Ans.append(Dict[i])
print(*Ans)