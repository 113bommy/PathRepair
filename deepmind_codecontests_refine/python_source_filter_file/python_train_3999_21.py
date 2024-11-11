counter = int(input())
magnets = ""
for i in range(counter):
    magnets += input()

print(magnets.count("11") + magnets.count("00"))