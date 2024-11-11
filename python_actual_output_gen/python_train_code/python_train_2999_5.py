ins = input()
ins.strip("0")
print(["NO", "YES"][ins == ins[::-1]])