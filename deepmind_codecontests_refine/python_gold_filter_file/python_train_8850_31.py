w, count = input(), 0

while True:
    line = input()
    if line == 'END_OF_TEXT':
        break
    count += line.lower().split().count(w)

print(count)