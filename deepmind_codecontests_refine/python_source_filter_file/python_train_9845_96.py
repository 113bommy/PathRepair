from collections import Counter
N = int(input())
results = input()
r = [i for i in results]
c = Counter(r)
if c["A"] < c["D"]:
    print("Dainik")
if c["A"] > c["D"]:
    print("Anton")
if c["A"] == c["D"]:
    print("Friendship")
