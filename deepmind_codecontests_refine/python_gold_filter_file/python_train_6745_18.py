a = input()
print(sum([a>b for a,b in zip(a,a[::-1])]))