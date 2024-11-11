ss = input()
tt = input()

print(sum([s==t for s, t in zip(ss,tt)]))