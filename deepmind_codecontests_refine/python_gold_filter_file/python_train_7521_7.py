list1 = [chr(i) for i in range(97, 123)]


def gen(k):
    l = len(k) + 1
    a = [["a" for i in range(200)] for i in range(l)]
    for i in range(l-1):
        a[i+1][:k[i]] = a[i][:k[i]]
        if k[i] < 200:
            a[i+1][k[i]] = "a" if a[i][k[i]] != "a" else "b"
    return a

test_number = int(input())
for _ in range(test_number):
    l = input()
    k = list(map(int, input().split()))
    for word in gen(k):
        for cha in word:
            print(cha, end="")
        print("")

