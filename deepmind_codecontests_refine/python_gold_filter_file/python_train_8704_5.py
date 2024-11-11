ins = input()
ins = ins.strip("0")

print(["NO", "YES"][ins == ins[::-1]])