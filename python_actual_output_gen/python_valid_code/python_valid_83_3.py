def teste(num):
    num = str(num)
    num = list(num)
    numaux = set(num)
    if len(numaux) == len(num):
        return "".join(num)
    else:
        return -1
a, b = map(int, input().split())
for i in range(a,b):
    ans = teste(i)
    if ans != -1:
        break
print(ans)