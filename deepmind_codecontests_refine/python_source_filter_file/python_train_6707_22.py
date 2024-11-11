string = input()
count = []
count.append(min((string.count("n") - 1) // 2, 0))
count.append(string.count("i"))
count.append(string.count("e") // 3)
count.append(string.count("t"))
print(min(count))


