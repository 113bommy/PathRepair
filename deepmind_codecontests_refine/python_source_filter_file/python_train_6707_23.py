string = input()
count = []
count.append((string.count("n") - 1) // 2)
count.append(string.count("i"))
count.append(string.count("e") // 3)
count.append(string.count("t"))
print(min(count))


